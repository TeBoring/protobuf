// -----------------------------------------------------------------------------
// NullValue
// -----------------------------------------------------------------------------

static zend_function_entry null_value_methods[] = {
  {NULL, NULL, NULL}
};

zend_class_entry* null_value_type;

// Init class entry.
PHP_PROTO_INIT_ENUMCLASS_START("Google\\Protobuf\\NullValue",
                                NullValue, null_value)
  zend_declare_class_constant_long(null_value_type,
                                   "NULL_VALUE", 10, 0 TSRMLS_CC);
PHP_PROTO_INIT_ENUMCLASS_END

