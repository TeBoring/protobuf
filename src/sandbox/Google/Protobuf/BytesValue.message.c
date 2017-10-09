// -----------------------------------------------------------------------------
// BytesValue
// -----------------------------------------------------------------------------

static zend_function_entry bytes_value_methods[] = {
  PHP_ME(BytesValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BytesValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BytesValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* bytes_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\BytesValue",
                                 BytesValue, bytes_value)
  zend_class_implements(bytes_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(bytes_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(BytesValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(bytes_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(BytesValue, bytes_value, Value, "value")

