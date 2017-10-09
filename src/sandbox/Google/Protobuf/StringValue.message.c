// -----------------------------------------------------------------------------
// StringValue
// -----------------------------------------------------------------------------

static zend_function_entry string_value_methods[] = {
  PHP_ME(StringValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(StringValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(StringValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* string_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\StringValue",
                                 StringValue, string_value)
  zend_class_implements(string_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(string_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(StringValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(string_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(StringValue, string_value, Value, "value")

