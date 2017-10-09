// -----------------------------------------------------------------------------
// BoolValue
// -----------------------------------------------------------------------------

static zend_function_entry bool_value_methods[] = {
  PHP_ME(BoolValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BoolValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BoolValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* bool_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\BoolValue",
                                 BoolValue, bool_value)
  zend_class_implements(bool_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(bool_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(BoolValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(bool_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(BoolValue, bool_value, Value, "value")

