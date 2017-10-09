// -----------------------------------------------------------------------------
// Mixin
// -----------------------------------------------------------------------------

static zend_function_entry mixin_methods[] = {
  PHP_ME(Mixin, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, getRoot, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, setRoot, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* mixin_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Mixin",
                                 Mixin, mixin)
  zend_class_implements(mixin_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(mixin_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(mixin_type, "root", strlen("root"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Mixin, __construct) {
  init_file_api();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(mixin_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Mixin, mixin, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Mixin, mixin, Root, "root")

