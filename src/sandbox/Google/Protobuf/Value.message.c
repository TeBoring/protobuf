// -----------------------------------------------------------------------------
// Value
// -----------------------------------------------------------------------------

static zend_function_entry value_methods[] = {
  PHP_ME(Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getNullValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setNullValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getNumberValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setNumberValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getStringValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setStringValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getBoolValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setBoolValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getStructValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setStructValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getListValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setListValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getKind, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Value",
                                 Value, value)
  zend_class_implements(value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(value_type, "kind", strlen("kind"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Value, __construct) {
  init_file_struct();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Value, value, NullValue, "null_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, NumberValue, "number_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, StringValue, "string_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, BoolValue, "bool_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, StructValue, "struct_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, ListValue, "list_value")
PHP_PROTO_ONEOF_ACCESSORS(Value, value, Kind, "kind")

