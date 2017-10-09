// -----------------------------------------------------------------------------
// FloatValue
// -----------------------------------------------------------------------------

static zend_function_entry float_value_methods[] = {
  PHP_ME(FloatValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FloatValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FloatValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* float_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\FloatValue",
                                 FloatValue, float_value)
  zend_class_implements(float_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(float_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(FloatValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(float_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(FloatValue, float_value, Value, "value")

