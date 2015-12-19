#include "protobuf.h"

#include <zend_hash.h>

// -----------------------------------------------------------------------------
// Global map from upb {msg,enum}defs to wrapper Descriptor/EnumDescriptor
// instances.
//
// -----------------------------------------------------------------------------

// This is a hash table from def objects (encoded by converting pointers to
// PHP integers) to MessageDef/EnumDef instances (as Ruby values).
HashTable* upb_def_to_php_obj_map;

void add_def_obj(const void* def, zval* value) {
  zend_hash_index_update(upb_def_to_php_obj_map, (zend_ulong)def, value,
                         sizeof(zval*), NULL);
}

zval* get_def_obj(const void* def) {
  zval* value;
  if (zend_hash_index_find(upb_def_to_php_obj_map, (zend_ulong)def, &value) ==
      FAILURE) {
    php_printf("PHP object not found for given definition.\n");
    return NULL;
  }
  return value;
}

// -----------------------------------------------------------------------------
// Utilities.
// -----------------------------------------------------------------------------

// Raises a PHP error if |status| is not OK, using its error message.
void check_upb_status(const upb_status* status, const char* msg) {
  if (!upb_ok(status)) {
    // char errmsg[100];
    // sprintf(errmsg,"%s: %s\n", msg, upb_status_errmsg(status));
    // zend_throw_exception(zend_exception_get_default(TSRMLS_C), errmsg,
    //                      0 TSRMLS_CC);
    // zend_throw_exception(zend_exception_get_default(TSRMLS_C), "AAAAAAA",
    //                      0 TSRMLS_CC);
    php_printf("%s: %s\n", upb_status_errmsg(status), msg);
  }
}

// define the function(s) we want to add
zend_function_entry protobuf_functions[] = {
  PHP_FE(cthulhu2, NULL)
  { NULL, NULL, NULL }
};

// "protobuf_functions" refers to the struct defined above
// we'll be filling in more of this later: you can use this to specify
// globals, php.ini info, startup and teardown functions, etc.
zend_module_entry protobuf_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_PROTOBUF_EXTNAME,
  protobuf_functions,
  PHP_MINIT(protobuf),
  NULL,
  NULL,
  NULL,
  NULL,
  PHP_PROTOBUF_VERSION,
  STANDARD_MODULE_PROPERTIES
};

// install module
ZEND_GET_MODULE(protobuf)

// actual non-template code!
PHP_FUNCTION(cthulhu2) {
  // php_printf is PHP's version of printf, it's essentially "echo" from C
  php_printf("In his house at R'lyeh dead Cthulhu waits dreaming 222.\n");
}

void init_global_variables(TSRMLS_D) {
  ALLOC_HASHTABLE(upb_def_to_php_obj_map);
  zend_hash_init(upb_def_to_php_obj_map, 16, NULL, NULL, 0);
}

PHP_MINIT_FUNCTION(protobuf) {
  protobuf_init_message(TSRMLS_C);
  init_global_variables(TSRMLS_C);
  DescriptorPool_init(TSRMLS_C);
  Descriptor_init(TSRMLS_C);
  MessageBuilderContext_init(TSRMLS_C);
  Builder_init(TSRMLS_C);
}
