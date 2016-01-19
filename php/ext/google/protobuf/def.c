#include "protobuf.h"

// -----------------------------------------------------------------------------
// Common Utilities
// -----------------------------------------------------------------------------

void check_upb_status(const upb_status* status, const char* msg) {
  if (!upb_ok(status)) {
    zend_error("%s: %s\n", msg, upb_status_errmsg(status));
  }
}


static upb_def *check_notfrozen(const upb_def *def) {
  if (upb_def_isfrozen(def)) {
    zend_error(E_ERROR,
               "Attempt to modify a frozen descriptor. Once descriptors are "
               "added to the descriptor pool, they may not be modified.");
  }
  return (upb_def *)def;
}

static upb_msgdef *check_msg_notfrozen(const upb_msgdef *def) {
  return upb_downcast_msgdef_mutable(check_notfrozen((const upb_def *)def));
}

static upb_fielddef *check_field_notfrozen(const upb_fielddef *def) {
  return upb_downcast_fielddef_mutable(check_notfrozen((const upb_def *)def));
}

#define PROTOBUF_SETUP_ZEND_OBJECT_VALUE(classname, object, intern)   \
  classname *intern = ALLOC(classname);                               \
  memset(intern, 0, sizeof(classname));                               \
  classname##_init_c_instance(intern);                                \
  object.handle = zend_objects_store_put(                             \
      intern, (zend_objects_store_dtor_t)zend_objects_destroy_object, \
      classname##_free, NULL TSRMLS_CC);                              \
  object.handlers = zend_get_std_object_handlers();

#define PROTOBUF_SETUP_ZEND_WRAPPER(classname, wrapper, intern) \
  Z_TYPE_P(wrapper) = IS_OBJECT;                                \
  PROTOBUF_SETUP_ZEND_OBJECT_VALUE(classname, Z_OBJVAL_P(wrapper), intern);

#define PROTOBUF_CREATE_ZEND_WRAPPER(classname, wrapper, intern) \
  MAKE_STD_ZVAL(wrapper);                                        \
  PROTOBUF_SETUP_ZEND_WRAPPER(classname, wrapper, intern);

#define DEFINE_CLASS(name, string_name)                                 \
  zend_class_entry *name##_type;                                        \
  void name##_init(TSRMLS_D) {                                          \
    zend_class_entry class_type;                                        \
    INIT_CLASS_ENTRY(class_type, string_name, name##_methods);          \
    name##_type = zend_register_internal_class(&class_type TSRMLS_CC);  \
    name##_type->create_object = name##_create;                         \
  }                                                                     \
  name *php_to_##name(zval *val TSRMLS_DC) {                            \
    return (name *)zend_object_store_get_object(val TSRMLS_CC);         \
  }                                                                     \
  zend_object_value name##_create(zend_class_entry *ce TSRMLS_DC) {     \
    zend_object_value return_value;                                     \
    name *intern = (name *)emalloc(sizeof(name));                       \
    memset(intern, 0, sizeof(name));                                    \
    name##_init_c_instance(intern);                                     \
    return_value.handle = zend_objects_store_put(                       \
        intern, (zend_objects_store_dtor_t)zend_objects_destroy_object, \
        name##_free, NULL TSRMLS_CC);                                   \
    return_value.handlers = zend_get_std_object_handlers();             \
    return return_value;                                                \
  }

#define PROTOBUF_UNWRAP_ZEND_WRAPPER(type, var, php_var) \
  type *var = php_to_##type(php_var)

// -----------------------------------------------------------------------------
// DescriptorPool
// -----------------------------------------------------------------------------

// Global singleton DescriptorPool. The user is free to create others, but this
// is used by generated code.
zval* generated_pool;

static zend_function_entry DescriptorPool_methods[] = {
  PHP_ME(DescriptorPool, new_builder, NULL, ZEND_ACC_PUBLIC)
  ZEND_FE_END
};

DEFINE_CLASS(DescriptorPool, "Google\\Protobuf\\DescriptorPool");

ZEND_FUNCTION(get_generated_pool) {
  if (generated_pool == NULL) {
    PROTOBUF_CREATE_ZEND_WRAPPER(DescriptorPool, generated_pool, intern);
  }
  RETURN_ZVAL(generated_pool, 0, 0);
}

void DescriptorPool_init_c_instance(DescriptorPool* pool TSRMLS_DC) {
  zend_object_std_init(&pool->std, DescriptorPool_type TSRMLS_CC);
  pool->symtab = upb_symtab_new(&pool->symtab);
}

void DescriptorPool_free(void *object TSRMLS_DC) {
  DescriptorPool *descriptor_pool = (DescriptorPool *)object;
  efree(descriptor_pool);
}

PHP_METHOD(DescriptorPool, new_builder) {
  PROTOBUF_UNWRAP_ZEND_WRAPPER(DescriptorPool, self, getThis());
  PROTOBUF_SETUP_ZEND_WRAPPER(Builder, return_value, builder);
  builder->pool = getThis();
}

// -----------------------------------------------------------------------------
// Descriptor
// -----------------------------------------------------------------------------

static zend_function_entry Descriptor_methods[] = {
  ZEND_FE_END
};

DEFINE_CLASS(Descriptor, "Google\\Protobuf\\Descriptor");

void Descriptor_free(void *object TSRMLS_DC) {
  Descriptor *descriptor = (Descriptor *)object;
  efree(descriptor);
}

static void Descriptor_add_field(Descriptor *desc,
                                 FieldDescriptor *field_desc) {
  upb_msgdef *mut_def = check_msg_notfrozen(desc->msgdef);
  upb_fielddef *mut_field_def = check_field_notfrozen(field_desc->fielddef);
  CHECK_UPB(upb_msgdef_addfield(mut_def, mut_field_def, NULL, &status),
            "Adding field to Descriptor failed");
  // add_def_obj(field_desc->fielddef, obj);
}

void Descriptor_init_c_instance(Descriptor* desc TSRMLS_DC) {
  zend_object_std_init(&desc->std, Descriptor_type TSRMLS_CC);
  desc->msgdef = upb_msgdef_new(&desc->msgdef);
  desc->layout = NULL;
  // MAKE_STD_ZVAL(intern->klass);
  // ZVAL_NULL(intern->klass);
  desc->pb_serialize_handlers = NULL;
}

void Descriptor_name_set(Descriptor *desc, const char *name) {
  upb_msgdef *mut_def = check_msg_notfrozen(desc->msgdef);
  CHECK_UPB(upb_msgdef_setfullname(mut_def, name, &status),
            "Error setting Descriptor name");
}

// -----------------------------------------------------------------------------
// FieldDescriptor
// -----------------------------------------------------------------------------

static void FieldDescriptor_name_set(FieldDescriptor *field_desc,
                                 const char* name) {
  upb_fielddef *mut_def = check_field_notfrozen(field_desc->fielddef);
  CHECK_UPB(upb_fielddef_setname(mut_def, name, &status),
            "Error setting FieldDescriptor name");
}

static void FieldDescriptor_label_set(FieldDescriptor *field_desc,
                                 const char* label) {
  upb_fielddef *mut_def = check_field_notfrozen(field_desc->fielddef);
  upb_label_t upb_label = -1;
  bool converted = false;

#define CONVERT(upb, str)        \
  if (!strcmp(label, str)) {     \
    upb_label = UPB_LABEL_##upb; \
    converted = true;            \
  }

  CONVERT(OPTIONAL, "optional");
  CONVERT(REQUIRED, "required");
  CONVERT(REPEATED, "repeated");

#undef CONVERT

  if (!converted) {
    zend_error(E_ERROR, "Unknown field label.");
  }

  upb_fielddef_setlabel(mut_def, upb_label);
}

upb_fieldtype_t string_to_descriptortype(const char *type) {
#define CONVERT(upb, str)   \
  if (!strcmp(type, str)) { \
    return UPB_DESCRIPTOR_TYPE_##upb;  \
  }

  CONVERT(FLOAT, "float");
  CONVERT(DOUBLE, "double");
  CONVERT(BOOL, "bool");
  CONVERT(STRING, "string");
  CONVERT(BYTES, "bytes");
  CONVERT(MESSAGE, "message");
  CONVERT(GROUP, "group");
  CONVERT(ENUM, "enum");
  CONVERT(INT32, "int32");
  CONVERT(INT64, "int64");
  CONVERT(UINT32, "uint32");
  CONVERT(UINT64, "uint64");
  CONVERT(SINT32, "sint32");
  CONVERT(SINT64, "sint64");
  CONVERT(FIXED32, "fixed32");
  CONVERT(FIXED64, "fixed64");
  CONVERT(SFIXED32, "sfixed32");
  CONVERT(SFIXED64, "sfixed64");

#undef CONVERT

  zend_error(E_ERROR, "Unknown field type.");
  return 0;
}

static void FieldDescriptor_type_set(FieldDescriptor *field_desc,
                                 const char* type) {
  upb_fielddef *mut_def = check_field_notfrozen(field_desc->fielddef);
  upb_fielddef_setdescriptortype(mut_def, string_to_descriptortype(type));
}

static void FieldDescriptor_number_set(FieldDescriptor *field_desc,
                                 int number) {
  upb_fielddef *mut_def = check_field_notfrozen(field_desc->fielddef);
  CHECK_UPB(upb_fielddef_setnumber(mut_def, number, &status),
            "Error setting field number");
}

// -----------------------------------------------------------------------------
// MessageBuilderContext
// -----------------------------------------------------------------------------

static zend_function_entry MessageBuilderContext_methods[] = {
    PHP_ME(MessageBuilderContext, finalize, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(MessageBuilderContext, optional, NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

DEFINE_CLASS(MessageBuilderContext,
             "Google\\Protobuf\\Internal\\MessageBuilderContext");

void MessageBuilderContext_free(void *object TSRMLS_DC) {
  MessageBuilderContext *descriptor = (MessageBuilderContext *)object;
  efree(descriptor);
}

void MessageBuilderContext_init_c_instance(
    MessageBuilderContext *context TSRMLS_DC) {
  zend_object_std_init(&context->std, MessageBuilderContext_type TSRMLS_CC);
  PROTOBUF_CREATE_ZEND_WRAPPER(Descriptor, context->descriptor, desc)
}

static void msgdef_add_field(Descriptor* desc,
                              const char* label, const char* name,
                              const char* type, int number,
                              const char* type_class) {
  FieldDescriptor *field_desc =
      (FieldDescriptor *)emalloc(sizeof(FieldDescriptor));
  memset(field_desc, 0, sizeof(FieldDescriptor));
  upb_fielddef *fielddef = upb_fielddef_new(&field_desc->fielddef);
  upb_fielddef_setpacked(fielddef, false);
  field_desc->fielddef = fielddef;

  FieldDescriptor_label_set(field_desc, label);
  FieldDescriptor_name_set(field_desc, name);
  FieldDescriptor_type_set(field_desc, type);
  FieldDescriptor_number_set(field_desc, number);

//   if (type_class != Qnil) {
//     if (TYPE(type_class) != T_STRING) {
//       rb_raise(rb_eArgError, "Expected string for type class");
//     }
//     // Make it an absolute type name by prepending a dot.
//     type_class = rb_str_append(rb_str_new2("."), type_class);
//     rb_funcall(fielddef, rb_intern("submsg_name="), 1, type_class);
//   }
  Descriptor_add_field(desc, field_desc);
}

PHP_METHOD(MessageBuilderContext, optional) {
  PROTOBUF_UNWRAP_ZEND_WRAPPER(MessageBuilderContext, self, getThis());
  PROTOBUF_UNWRAP_ZEND_WRAPPER(Descriptor, desc, self->descriptor);
  // VALUE name, type, number, type_class;
  const char *name, *type, *type_class;
  int number, name_str_len, type_str_len, type_class_str_len;
  if (ZEND_NUM_ARGS() == 3) {
    if (zend_parse_parameters(3 TSRMLS_CC, "ssl", &name,
                              &name_str_len, &type, &type_str_len, &number) == FAILURE) {
      return;
    }
  } else {
    if (zend_parse_parameters(4 TSRMLS_CC, "ssls", &name,
                              &name_str_len, &type, &type_str_len, &number, &type_class,
                              &type_class_str_len) == FAILURE) {
      return;
    }
  }

  msgdef_add_field(desc, "optional", name, type, number, type_class);

  // if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "OO",
  //                           &intern->descriptor, Descriptor_type,
  //                           &intern->builder, Builder_type) == FAILURE) {
  //   return;
  // }

  // if (argc < 3) {
  //   rb_raise(rb_eArgError, "Expected at least 3 arguments.");
  // }
  // name = argv[0];
  // type = argv[1];
  // number = argv[2];
  // type_class = (argc > 3) ? argv[3] : Qnil;

  // return msgdef_add_field(self->descriptor, "optional",
  //                         name, type, number, type_class);
  RETURN_ZVAL(getThis(), 0, 1);
}

PHP_METHOD(MessageBuilderContext, finalize) {
  PROTOBUF_UNWRAP_ZEND_WRAPPER(MessageBuilderContext, self, getThis());
  PROTOBUF_UNWRAP_ZEND_WRAPPER(Builder, builder, self->builder);
  add_next_index_zval(builder->pending_list, self->descriptor);
  RETURN_ZVAL(self->builder, 0, 1);
}

// -----------------------------------------------------------------------------
// Builder
// -----------------------------------------------------------------------------

static zend_function_entry Builder_methods[] = {
  // PHP_ME(Builder, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Builder, add_message, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Builder, finalize_to_pool, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

DEFINE_CLASS(Builder, "Google\\Protobuf\\Internal\\Builder");

// PHP_METHOD(Builder, __construct) {
//   Builder *intern = zend_object_store_get_object(getThis() TSRMLS_CC);
//   MAKE_STD_ZVAL(intern->pending_list);
//   array_init(intern->pending_list);
// }

void Builder_free(void *object TSRMLS_DC) {
  Builder *descriptor = (Builder *)object;
  efree(descriptor);
}

void Builder_init_c_instance(Builder *builder TSRMLS_DC) {
  zend_object_std_init(&builder->std, Builder_type TSRMLS_CC);
  MAKE_STD_ZVAL(builder->pending_list);
  array_init(builder->pending_list);
}

static void validate_msgdef(const upb_msgdef* msgdef) {
  // Verify that no required fields exist. proto3 does not support these.
  upb_msg_field_iter it;
  for (upb_msg_field_begin(&it, msgdef);
       !upb_msg_field_done(&it);
       upb_msg_field_next(&it)) {
    const upb_fielddef* field = upb_msg_iter_field(&it);
    if (upb_fielddef_label(field) == UPB_LABEL_REQUIRED) {
      zend_error(E_ERROR, "Required fields are unsupported in proto3.");
    }
  }
}

PHP_METHOD(Builder, add_message) {
  char *name = NULL;
  int str_len;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &str_len) ==
      FAILURE) {
    return;
  }

  PROTOBUF_SETUP_ZEND_WRAPPER(MessageBuilderContext, return_value, context);
  MAKE_STD_ZVAL(context->builder);
  ZVAL_ZVAL(context->builder, getThis(), 1, 0);

  PROTOBUF_UNWRAP_ZEND_WRAPPER(Descriptor, desc, context->descriptor);
  Descriptor_name_set(desc, name);
}

PHP_METHOD(Builder, finalize_to_pool) {
  PROTOBUF_UNWRAP_ZEND_WRAPPER(Builder, self, getThis());
  PROTOBUF_UNWRAP_ZEND_WRAPPER(DescriptorPool, pool, self->pool);

  self->defs = emalloc(sizeof(upb_def *) * Z_ARRVAL_SIZE_P(self->pending_list));

  int i = 0;
  Bucket *entry = Z_ARRVAL_BEGIN_P(self->pending_list);
  while (entry != NULL) {
    zval *def_php = *(zval **)entry->pData;
    Descriptor* desc = php_to_Descriptor(def_php);
    self->defs[i] = (upb_def *)desc->msgdef;
    validate_msgdef((const upb_msgdef *)self->defs[i]);
    Z_BUCKET_NEXT_PP(&entry);
    i++;
    // if (CLASS_OF(def_rb) == cDescriptor) {
    //   self->defs[i] = (upb_def*)ruby_to_Descriptor(def_rb)->msgdef;
    //   validate_msgdef((const upb_msgdef*)self->defs[i]);
    // } else if (CLASS_OF(def_rb) == cEnumDescriptor) {
    //   self->defs[i] = (upb_def*)ruby_to_EnumDescriptor(def_rb)->enumdef;
    //   validate_enumdef((const upb_enumdef*)self->defs[i]);
    // }
  }

  CHECK_UPB(upb_symtab_add(pool->symtab, (upb_def **)self->defs,
                           Z_ARRVAL_SIZE_P(self->pending_list), NULL, &status),
            "Unable to add defs to DescriptorPool");

  i = 0;
  entry = Z_ARRVAL_BEGIN_P(self->pending_list);
  while (entry != NULL) {
    zval *def_php = *(zval **)entry->pData;
    Descriptor* desc = php_to_Descriptor(def_php);
    build_class_from_descriptor(desc);
    add_def_obj(self->defs[i], *(zval **)entry->pData);
    Z_BUCKET_NEXT_PP(&entry);
    i++;
  }

  array_init(self->pending_list);
}
