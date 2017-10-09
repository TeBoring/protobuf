// -----------------------------------------------------------------------------
// Struct
// -----------------------------------------------------------------------------

static zend_function_entry struct_methods[] = {
  PHP_ME(Struct, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Struct, getFields, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Struct, setFields, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* struct_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Struct",
                                 Struct, struct)
  zend_class_implements(struct_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(struct_type, "fields", strlen("fields"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Struct, __construct) {
  init_file_struct();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(struct_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Struct, struct, Fields, "fields")

