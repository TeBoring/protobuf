// -----------------------------------------------------------------------------
// Api
// -----------------------------------------------------------------------------

static zend_function_entry api_methods[] = {
  PHP_ME(Api, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getMethods, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setMethods, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getVersion, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setVersion, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getMixins, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setMixins, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getSyntax, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setSyntax, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* api_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Api",
                                 Api, api)
  zend_class_implements(api_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(api_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "methods", strlen("methods"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "version", strlen("version"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "source_context", strlen("source_context"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "mixins", strlen("mixins"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "syntax", strlen("syntax"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Api, __construct) {
  init_file_api();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(api_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Api, api, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Methods, "methods")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Options, "options")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Version, "version")
PHP_PROTO_FIELD_ACCESSORS(Api, api, SourceContext, "source_context")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Mixins, "mixins")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Syntax, "syntax")

