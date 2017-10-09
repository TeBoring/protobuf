// -----------------------------------------------------------------------------
// FieldMask
// -----------------------------------------------------------------------------

static zend_function_entry field_mask_methods[] = {
  PHP_ME(FieldMask, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FieldMask, getPaths, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FieldMask, setPaths, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* field_mask_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\FieldMask",
                                 FieldMask, field_mask)
  zend_class_implements(field_mask_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(field_mask_type, "paths", strlen("paths"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(FieldMask, __construct) {
  init_file_field_mask();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(field_mask_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(FieldMask, field_mask, Paths, "paths")

