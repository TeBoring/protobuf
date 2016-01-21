// Protocol Buffers - Google's data interchange format
// Copyright 2014 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <php.h>

#include "protobuf.h"

// -----------------------------------------------------------------------------
// Class/module creation from msgdefs and enumdefs, respectively.
// -----------------------------------------------------------------------------

static zend_object_handlers* Message_handlers;

void* Message_data(void* msg) {
  return ((uint8_t *)msg) + sizeof(MessageHeader);
}

void Message_set_property(zval* object, zval* field_name, zval* value,
                          const zend_literal* key TSRMLS_DC) {
  const upb_fielddef* field;

  MessageHeader* self = zend_object_store_get_object(object TSRMLS_CC);

  CHECK_TYPE(field_name, IS_STRING);
  field = upb_msgdef_ntofz(self->descriptor->msgdef, Z_STRVAL_P(field_name));
  if (field == NULL) {
    zend_error(E_ERROR, "Unknown field: %s", Z_STRVAL_P(field_name));
  }
  layout_set(self->descriptor->layout, Message_data(self), field, value);
}

zval* Message_get_property(zval* object, zval* member, int type,
                             const zend_literal* key TSRMLS_DC) {
  MessageHeader* self =
      (MessageHeader*)zend_object_store_get_object(object TSRMLS_CC);
  CHECK_TYPE(member, IS_STRING);

  const upb_fielddef* field;
  field = upb_msgdef_ntofz(self->descriptor->msgdef, Z_STRVAL_P(member));
  if (field == NULL) {
    return EG(uninitialized_zval_ptr);
  }
  zval* retval = layout_get(self->descriptor->layout, Message_data(self), field TSRMLS_CC);
  php_printf("retval#3: %p\n", retval);
  return retval;
}

static  zend_function_entry Message_methods[] = {
  PHP_ME(Message, encode, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

/* stringsink *****************************************************************/

// This should probably be factored into a common upb component.

typedef struct {
  upb_byteshandler handler;
  upb_bytessink sink;
  char *ptr;
  size_t len, size;
} stringsink;

static void *stringsink_start(void *_sink, const void *hd, size_t size_hint) {
  stringsink *sink = _sink;
  sink->len = 0;
  return sink;
}

static size_t stringsink_string(void *_sink, const void *hd, const char *ptr,
                                size_t len, const upb_bufhandle *handle) {
  stringsink *sink = _sink;
  size_t new_size = sink->size;

  UPB_UNUSED(hd);
  UPB_UNUSED(handle);

  while (sink->len + len > new_size) {
    new_size *= 2;
  }

  if (new_size != sink->size) {
    sink->ptr = realloc(sink->ptr, new_size);
    sink->size = new_size;
  }

  memcpy(sink->ptr + sink->len, ptr, len);
  sink->len += len;

  return len;
}

void stringsink_init(stringsink *sink) {
  upb_byteshandler_init(&sink->handler);
  upb_byteshandler_setstartstr(&sink->handler, stringsink_start, NULL);
  upb_byteshandler_setstring(&sink->handler, stringsink_string, NULL);

  upb_bytessink_reset(&sink->sink, &sink->handler, sink);

  sink->size = 32;
  sink->ptr = malloc(sink->size);
  sink->len = 0;
}

void stringsink_uninit(stringsink *sink) { free(sink->ptr); }

// Stack-allocated context during an encode/decode operation. Contains the upb
// environment and its stack-based allocator, an initial buffer for allocations
// to avoid malloc() when possible, and a template for PHP exception messages
// if any error occurs.
#define STACK_ENV_STACKBYTES 4096
typedef struct {
  upb_env env;
  upb_seededalloc alloc;
  const char *php_error_template;
  char allocbuf[STACK_ENV_STACKBYTES];
} stackenv;

static void stackenv_init(stackenv* se, const char* errmsg);
static void stackenv_uninit(stackenv* se);

// Callback invoked by upb if any error occurs during parsing or serialization.
static bool env_error_func(void* ud, const upb_status* status) {
    stackenv* se = ud;
    // Free the env -- rb_raise will longjmp up the stack past the encode/decode
    // function so it would not otherwise have been freed.
    stackenv_uninit(se);

    // TODO(teboring): have a way to verify that this is actually a parse error,
    // instead of just throwing "parse error" unconditionally.
    zend_error(E_ERROR, se->php_error_template);
    // Never reached.
    return false;
}

static void stackenv_init(stackenv* se, const char* errmsg) {
  se->php_error_template = errmsg;
  upb_env_init(&se->env);
  upb_seededalloc_init(&se->alloc, &se->allocbuf, STACK_ENV_STACKBYTES);
  upb_env_setallocfunc(&se->env, upb_seededalloc_getallocfunc(&se->alloc),
                       &se->alloc);
  upb_env_seterrorfunc(&se->env, env_error_func, se);
}

static void stackenv_uninit(stackenv* se) {
  upb_env_uninit(&se->env);
  upb_seededalloc_uninit(&se->alloc);
}

// -----------------------------------------------------------------------------
// Message
// -----------------------------------------------------------------------------

static const upb_handlers* msgdef_pb_serialize_handlers(Descriptor* desc) {
  if (desc->pb_serialize_handlers == NULL) {
    php_printf("before create serialize handler, %ld\n", desc);
    desc->pb_serialize_handlers =
        upb_pb_encoder_newhandlers(desc->msgdef, &desc->pb_serialize_handlers);
    php_printf("after create serialize handler");
  }
  return desc->pb_serialize_handlers;
}

PHP_METHOD(Message, encode) {
  Descriptor* desc = (Descriptor*)zend_object_store_get_object(
      CE_STATIC_MEMBERS(Z_OBJCE_P(getThis()))[0] TSRMLS_CC);
  php_printf("encode descriptor 1\n");

  stringsink sink;
  stringsink_init(&sink);

  {
  php_printf("encode descriptor 2\n");
    const upb_handlers* serialize_handlers = msgdef_pb_serialize_handlers(desc);

  php_printf("encode descriptor 3\n");
    stackenv se;
    upb_pb_encoder* encoder;
    // VALUE ret;

  php_printf("encode descriptor 4\n");
    stackenv_init(&se, "Error occurred during encoding: %s");
    encoder = upb_pb_encoder_create(&se.env, serialize_handlers, &sink.sink);

  php_printf("encode descriptor 5\n");
    putmsg(getThis(), desc, upb_pb_encoder_input(encoder), 0);

    // ret = rb_str_new(sink.ptr, sink.len);
    RETVAL_STRINGL(sink.ptr, sink.len, 1);

  php_printf("encode descriptor 6 %d\n", sink.len);
    stackenv_uninit(&se);
    stringsink_uninit(&sink);
  php_printf("encode descriptor 7\n");
  }
}

void Message_free(void * object TSRMLS_DC) {
  FREE(MessageHeader, object);
}

zend_object_value Message_create(zend_class_entry* ce TSRMLS_DC) {
  php_printf("Message_create start\n");
  zend_object_value return_value;

  Descriptor* desc = zend_object_store_get_object(
      CE_STATIC_MEMBERS(ce)[0] TSRMLS_CC);
  MessageHeader* msg = (MessageHeader*)ALLOC_N(
      uint8_t, sizeof(MessageHeader) + desc->layout->size);
  memset(Message_data(msg), 0, desc->layout->size);

  // We wrap first so that everything in the message object is GC-rooted in case
  // a collection happens during object creation in layout_init().
  msg->descriptor = desc;

  layout_init(desc->layout, Message_data(msg));
  zend_object_std_init(&msg->std, ce TSRMLS_CC);

  return_value.handle = zend_objects_store_put(
      msg, (zend_objects_store_dtor_t)zend_objects_destroy_object,
      Message_free, NULL TSRMLS_CC);

  return_value.handlers = Message_handlers;
  // return_value.handlers = zend_get_std_object_handlers();
  php_printf("Message_create end\n");
  return return_value;
}

const zend_class_entry* build_class_from_descriptor(Descriptor* desc TSRMLS_DC) {
  if (desc->layout == NULL) {
    MessageLayout* layout = create_layout(desc->msgdef);
    desc->layout = layout;
  }
  // if (desc->fill_method == NULL) {
  //   desc->fill_method = new_fillmsg_decodermethod(desc, &desc->fill_method);
  // }

  const char* name = upb_msgdef_fullname(desc->msgdef);
  if (name == NULL) {
    zend_error(E_ERROR, "Descriptor does not have assigned name.");
  }

  zend_class_entry class_entry;
  INIT_CLASS_ENTRY_EX(class_entry, name, strlen(name), Message_methods);
  zend_class_entry* registered_ce =
      zend_register_internal_class(&class_entry TSRMLS_CC);

  DEFINE_PHP_WRAPPER(Descriptor, php_desc, desc);
#ifdef ZTS
  CG(static_members_table)[(zend_intptr_t)(registered_ce)->static_members_table] = ALLOC(zval*);
#else
  CE_STATIC_MEMBERS(registered_ce) = ALLOC(zval*)
#endif
  CE_STATIC_MEMBERS(registered_ce)[0] = php_desc;

  if (Message_handlers == NULL) {
    Message_handlers = ALLOC(zend_object_handlers);
    memcpy(Message_handlers, zend_get_std_object_handlers(),
           sizeof(zend_object_handlers));
    Message_handlers->write_property = Message_set_property;
    Message_handlers->read_property = Message_get_property;
  }

  registered_ce->create_object = Message_create;
}
