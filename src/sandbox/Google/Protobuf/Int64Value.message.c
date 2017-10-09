// -----------------------------------------------------------------------------
// Int64Value
// -----------------------------------------------------------------------------

static zend_function_entry int64_value_methods[] = {
  PHP_ME(Int64Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Int64Value, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Int64Value, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* int64_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Int64Value",
                                 Int64Value, int64_value)
  zend_class_implements(int64_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(int64_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Int64Value, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(int64_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Int64Value, int64_value, Value, "value")

