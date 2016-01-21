#ifndef __GOOGLE_PROTOBUF_PHP_PROTOBUF_H__
#define __GOOGLE_PROTOBUF_PHP_PROTOBUF_H__

#include <php.h>

#include "upb.h"

#define PHP_PROTOBUF_EXTNAME "protobuf"
#define PHP_PROTOBUF_VERSION "0.01"

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
extern zend_class_entry* Descriptor_type;
extern zend_class_entry* MessageBuilderContext_type;

extern zval* generated_pool;

// -----------------------------------------------------------------------------
// PHP functions and global variables.
// -----------------------------------------------------------------------------

PHP_MINIT_FUNCTION(protobuf);

// ZEND_BEGIN_MODULE_GLOBALS(protobuf)
//   zval* generated_pool;
// ZEND_END_MODULE_GLOBALS(protobuf)

// -----------------------------------------------------------------------------
// PHP class structure.
// -----------------------------------------------------------------------------

struct DescriptorPool {
  zend_object std;
  upb_symtab* symtab;
};

struct Descriptor {
  zend_object std;
  const upb_msgdef* msgdef;
  MessageLayout* layout;
  // zval* klass;  // begins as NULL
  // const upb_handlers* fill_handlers;
  // const upb_pbdecodermethod* fill_method;
  const upb_handlers* pb_serialize_handlers;
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

// -----------------------------------------------------------------------------
// Native slot storage abstraction.
// -----------------------------------------------------------------------------

#define NATIVE_SLOT_MAX_SIZE sizeof(uint64_t)

size_t native_slot_size(upb_fieldtype_t type);

#define MAP_KEY_FIELD 1
#define MAP_VALUE_FIELD 2

// Oneof case slot value to indicate that no oneof case is set. The value `0` is
// safe because field numbers are used as case identifiers, and no field can
// have a number of 0.
#define ONEOF_CASE_NONE 0

// These operate on a map field (i.e., a repeated field of submessages whose
// submessage type is a map-entry msgdef).
bool is_map_field(const upb_fielddef* field);
const upb_fielddef* map_field_key(const upb_fielddef* field);
const upb_fielddef* map_field_value(const upb_fielddef* field);

// These operate on a map-entry msgdef.
const upb_fielddef* map_entry_key(const upb_msgdef* msgdef);
const upb_fielddef* map_entry_value(const upb_msgdef* msgdef);

// -----------------------------------------------------------------------------
// Message layout / storage.
// -----------------------------------------------------------------------------

#define MESSAGE_FIELD_NO_CASE ((size_t)-1)

struct MessageField {
  size_t offset;
  size_t case_offset;  // for oneofs, a uint32. Else, MESSAGE_FIELD_NO_CASE.
};

struct MessageLayout {
  const upb_msgdef* msgdef;
  MessageField* fields;
  size_t size;
};

void layout_init(MessageLayout* layout, void* storage);
zval* layout_get(MessageLayout* layout, const void* storage,
                 const upb_fielddef* field TSRMLS_DC);
MessageLayout* create_layout(const upb_msgdef* msgdef);
zval* native_slot_get(upb_fieldtype_t type, /*VALUE type_class,*/
                      const void* memory TSRMLS_DC);

// -----------------------------------------------------------------------------
// Message class creation.
// -----------------------------------------------------------------------------

struct MessageHeader {
  zend_object std;
  Descriptor* descriptor;  // kept alive by self.class.descriptor reference.
                           // Data comes after this.
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
  zval* pool;
};

// Forward-declare all of the PHP method implementations.

DescriptorPool* php_to_DescriptorPool(zval* value TSRMLS_DC);
zend_object_value DescriptorPool_create(zend_class_entry *ce TSRMLS_DC);
void DescriptorPool_free(void* object TSRMLS_DC);
void DescriptorPool_init_c_instance(DescriptorPool* pool TSRMLS_DC);
PHP_METHOD(DescriptorPool, new_builder);

Descriptor* php_to_Descriptor(zval* value TSRMLS_DC);
zend_object_value Descriptor_create(zend_class_entry *ce TSRMLS_DC);
void Descriptor_init_c_instance(Descriptor* intern TSRMLS_DC);
void Descriptor_free(void* object TSRMLS_DC);
void Descriptor_name_set(Descriptor *desc, const char *name);

MessageBuilderContext* php_to_MessageBuilderContext(zval* value TSRMLS_DC);
zend_object_value MessageBuilderContext_create(zend_class_entry* ce TSRMLS_DC);
void MessageBuilderContext_init_c_instance(MessageBuilderContext* intern TSRMLS_DC);
void MessageBuilderContext_free(void* object TSRMLS_DC);
PHP_METHOD(MessageBuilderContext, optional);
PHP_METHOD(MessageBuilderContext, finalize);

Builder* php_to_Builder(zval* value TSRMLS_DC);
zend_object_value Builder_create(zend_class_entry* ce TSRMLS_DC);
void Builder_init_c_instance(Builder* intern TSRMLS_DC);
void Builder_free(void* object TSRMLS_DC);
PHP_METHOD(Builder, add_message);
PHP_METHOD(Builder, finalize_to_pool);

PHP_METHOD(Message, encode);

PHP_FUNCTION(get_generated_pool);

// -----------------------------------------------------------------------------
// Global map from upb {msg,enum}defs to wrapper Descriptor/EnumDescriptor
// instances.
// ----------------------------------------------------------------------------

void add_def_obj(const void* def, zval* value);
zval* get_def_obj(const void* def);

// -----------------------------------------------------------------------------
// Utilities.
// -----------------------------------------------------------------------------

// Access global variables.
#ifdef ZTS
#define PROTOBUF_G(v) TSRMG(protobuf_globals_id, zend_protobuf_globals*, v)
#else
#define PROTOBUF_G(v) (protobuf_globals.v)
#endif

#define Z_ARRVAL_SIZE_P(zval_p) zend_hash_num_elements(Z_ARRVAL_P(zval_p))
#define Z_ARRVAL_BEGIN_P(zval_p) Z_ARRVAL_P(zval_p)->pListHead
#define Z_BUCKET_NEXT_PP(bucket_pp) *bucket_pp = (*bucket_pp)->pListNext

#define DEFINE_PHP_OBJECT(classname, name)  \
  do {                                      \
    zval* name;                             \
    MAKE_STD_ZVAL(name);                    \
    object_init_ex(name, classname##_type); \
  } while (0)

#define DEFINE_PHP_WRAPPER(classname, name, intern)                   \
  zval* name;                                                         \
  MAKE_STD_ZVAL(name);                                                \
  object_init_ex(name, classname##_type);                             \
  Z_OBJVAL_P(name)                                                    \
      .handle = zend_objects_store_put(                               \
      intern, (zend_objects_store_dtor_t)zend_objects_destroy_object, \
      classname##_free, NULL TSRMLS_CC);

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

// Upb Utilities

void check_upb_status(const upb_status* status, const char* msg);

#define CHECK_UPB(code, msg)             \
  do {                                   \
    upb_status status = UPB_STATUS_INIT; \
    code;                                \
    check_upb_status(&status, msg);      \
  } while (0)

// Memory management

#define ALLOC(classname) (classname*) emalloc(sizeof(classname))
#define ALLOC_N(classname, n) (classname*) emalloc(sizeof(classname) * n)
#define FREE(classname, object) efree((classname*)object)

// Type Checking
#define CHECK_TYPE(field, type)             \
  if (Z_TYPE_P(field) != type) {            \
    zend_error(E_ERROR, "Unexpected type"); \
  }

#endif  // __GOOGLE_PROTOBUF_PHP_PROTOBUF_H__
