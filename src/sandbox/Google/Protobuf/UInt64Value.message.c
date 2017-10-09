// -----------------------------------------------------------------------------
// UInt64Value
// -----------------------------------------------------------------------------

static zend_function_entry u_int64_value_methods[] = {
  PHP_ME(UInt64Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(UInt64Value, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(UInt64Value, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* u_int64_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\UInt64Value",
                                 UInt64Value, u_int64_value)
  zend_class_implements(u_int64_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(u_int64_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(UInt64Value, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(u_int64_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(UInt64Value, u_int64_value, Value, "value")

