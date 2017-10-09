// -----------------------------------------------------------------------------
// SourceContext
// -----------------------------------------------------------------------------

static zend_function_entry source_context_methods[] = {
  PHP_ME(SourceContext, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(SourceContext, getFileName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(SourceContext, setFileName, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* source_context_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\SourceContext",
                                 SourceContext, source_context)
  zend_class_implements(source_context_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(source_context_type, "file_name", strlen("file_name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(SourceContext, __construct) {
  init_file_source_context();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(source_context_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(SourceContext, source_context, FileName, "file_name")

