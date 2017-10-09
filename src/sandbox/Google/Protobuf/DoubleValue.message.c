// -----------------------------------------------------------------------------
// DoubleValue
// -----------------------------------------------------------------------------

static zend_function_entry double_value_methods[] = {
  PHP_ME(DoubleValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(DoubleValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(DoubleValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* double_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\DoubleValue",
                                 DoubleValue, double_value)
  zend_class_implements(double_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(double_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(DoubleValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(double_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(DoubleValue, double_value, Value, "value")

