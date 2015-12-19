#ifndef __GOOGLE_PROTOBUF_PHP_PROTOBUF_H__
#define __GOOGLE_PROTOBUF_PHP_PROTOBUF_H__

#include <php.h>

#include "upb.h"

#define PHP_PROTOBUF_EXTNAME "protobuf"
#define PHP_PROTOBUF_VERSION "0.01"

PHP_FUNCTION(cthulhu2);
PHP_MINIT_FUNCTION(protobuf);

// Forward decls.
struct DescriptorPool;
struct Descriptor;
struct FieldDescriptor;
struct EnumDescriptor;
struct MessageLayout;
struct MessageField;
struct MessageHeader;
struct MessageBuilderContext;
struct EnumBuilderContext;
struct Builder;

typedef struct DescriptorPool DescriptorPool;
typedef struct Descriptor Descriptor;
typedef struct FieldDescriptor FieldDescriptor;
typedef struct OneofDescriptor OneofDescriptor;
typedef struct EnumDescriptor EnumDescriptor;
typedef struct MessageLayout MessageLayout;
typedef struct MessageField MessageField;
typedef struct MessageHeader MessageHeader;
typedef struct MessageBuilderContext MessageBuilderContext;
typedef struct OneofBuilderContext OneofBuilderContext;
typedef struct EnumBuilderContext EnumBuilderContext;
typedef struct Builder Builder;

extern zend_class_entry* Builder_type;

// -----------------------------------------------------------------------------
// PHP class structure definitions.
// -----------------------------------------------------------------------------

struct DescriptorPool {
  zend_object std;
  upb_symtab* symtab;
};

struct Descriptor {
  zend_object std;
  const upb_msgdef* msgdef;
  // MessageLayout* layout;
  // zval* klass;  // begins as NULL
  // const upb_handlers* fill_handlers;
  // const upb_pbdecodermethod* fill_method;
  // const upb_handlers* pb_serialize_handlers;
  // const upb_handlers* json_serialize_handlers;
  // Handlers hold type class references for sub-message fields directly in some
  // cases. We need to keep these rooted because they might otherwise be
  // collected.
  // zval_array typeclass_references;
};

struct FieldDescriptor {
  zend_object std;
  const upb_fielddef* fielddef;
};

struct OneofDescriptor {
  zend_object std;
  const upb_oneofdef* oneofdef;
};

struct EnumDescriptor {
  zend_object std;
  const upb_enumdef* enumdef;
  // VALUE module;  // begins as nil
};

struct MessageBuilderContext {
  zend_object std;
  zval* descriptor;
  zval* builder;
};

struct OneofBuilderContext {
  zend_object std;
  // VALUE descriptor;
  // VALUE builder;
};

struct EnumBuilderContext {
  zend_object std;
  // VALUE enumdesc;
};

struct Builder {
  zend_object std;
  zval* pending_list;
  upb_def** defs;  // used only while finalizing
};

// Forward-declare all of the PHP method implementations.

DescriptorPool* php_to_DescriptorPool(zval* value TSRMLS_DC);
zend_object_value DescriptorPool_create(zend_class_entry *ce TSRMLS_DC);
void DescriptorPool_free(void* object TSRMLS_DC);
PHP_METHOD(DescriptorPool, __construct);
PHP_METHOD(DescriptorPool, add);
PHP_METHOD(DescriptorPool, build);
PHP_METHOD(DescriptorPool, search);

Descriptor* php_to_Descriptor(zval* value TSRMLS_DC);
zend_object_value Descriptor_create(zend_class_entry *ce TSRMLS_DC);
void Descriptor_init_intern(Descriptor* intern TSRMLS_DC);
void Descriptor_free(void* object TSRMLS_DC);
PHP_METHOD(Descriptor, __construct);
PHP_METHOD(Descriptor, name_set);

MessageBuilderContext* php_to_MessageBuilderContext(zval* value TSRMLS_DC);
zend_object_value MessageBuilderContext_create(zend_class_entry* ce TSRMLS_DC);
void MessageBuilderContext_init_intern(MessageBuilderContext* intern TSRMLS_DC);
void MessageBuilderContext_free(void* object TSRMLS_DC);
PHP_METHOD(MessageBuilderContext, __construct);
PHP_METHOD(MessageBuilderContext, optional);

Builder* php_to_Builder(zval* value TSRMLS_DC);
zend_object_value Builder_create(zend_class_entry* ce TSRMLS_DC);
void Builder_init_intern(Builder* intern TSRMLS_DC);
void Builder_free(void* object TSRMLS_DC);
PHP_METHOD(Builder, __construct);
PHP_METHOD(Builder, add_message);
PHP_METHOD(Builder, finalize_to_pool);

// -----------------------------------------------------------------------------
// Global map from upb {msg,enum}defs to wrapper Descriptor/EnumDescriptor
// instances.
//
// ----------------------------------------------------------------------------

void add_def_obj(const void* def, zval* value);
zval* get_def_obj(const void* def);

// -----------------------------------------------------------------------------
// Utilities.
// -----------------------------------------------------------------------------

#define Z_ARRVAL_SIZE_P(zval_p) zend_hash_num_elements(Z_ARRVAL_P(zval_p))
#define Z_ARRVAL_BEGIN_P(zval_p) Z_ARRVAL_P(zval_p)->pListHead
#define Z_BUCKET_NEXT_PP(bucket_pp) *bucket_pp = (*bucket_pp)->pListNext

#define DEFINE_PHP_OBJECT(classname, name)  \
  do {                                      \
    zval* name;                             \
    MAKE_STD_ZVAL(name);                    \
    object_init_ex(name, classname##_type); \
  } while (0)

#define DEFINE_PHP_ZVAL(name) \
  do {                        \
    zval* name;               \
    MAKE_STD_ZVAL(name);      \
  } while (0)

#define DEFINE_PHP_STRING(name, value) \
  do {                                 \
    zval* name;                        \
    MAKE_STD_ZVAL(name);               \
    ZVAL_STRING(name, value, 1);       \
  } while (0)

// PHP Method Calling

#define PUSH_PARAM(arg) zend_vm_stack_push(arg TSRMLS_CC)
#define POP_PARAM() (void) zend_vm_stack_pop(TSRMLS_C)
#define PUSH_EO_PARAM()
#define POP_EO_PARAM()

#define CALL_METHOD_BASE(classname, name) zim_##classname##_##name

#define CALL_METHOD_HELPER(classname, name, retval, thisptr, num, param)      \
  PUSH_PARAM(param);                                                          \
  PUSH_PARAM((void*)num);                                                     \
  PUSH_EO_PARAM();                                                            \
  CALL_METHOD_BASE(classname, name)(num, retval, NULL, thisptr, 0 TSRMLS_CC); \
  POP_EO_PARAM();                                                             \
  POP_PARAM();                                                                \
  POP_PARAM();

#define CALL_METHOD(classname, name, retval, thisptr) \
  CALL_METHOD_BASE(classname, name)(0, retval, NULL, thisptr, 0 TSRMLS_CC);

#define CALL_METHOD1(classname, name, retval, thisptr, param1) \
  CALL_METHOD_HELPER(classname, name, retval, thisptr, 1, param1);

void check_upb_status(const upb_status* status, const char* msg);

#define CHECK_UPB(code, msg)             \
  do {                                   \
    upb_status status = UPB_STATUS_INIT; \
    code;                                \
    check_upb_status(&status, msg);      \
  } while (0)

#endif  // __GOOGLE_PROTOBUF_PHP_PROTOBUF_H__
