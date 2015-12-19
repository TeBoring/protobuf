#include "protobuf.h"

// -----------------------------------------------------------------------------
// Common Utilities
// -----------------------------------------------------------------------------

static upb_def *check_notfrozen(const upb_def *def) {
  if (upb_def_isfrozen(def)) {
    // zend_throw_exception(
    //     zend_exception_get_default(TSRMLS_C),
    //     "Attempt to modify a frozen descriptor. Once descriptors are "
    //     "added to the descriptor pool, they may not be modified.",
    //     0 TSRMLS_CC);
    php_printf("is frozen\n");
  }
  return (upb_def *)def;
}

static upb_msgdef* check_msg_notfrozen(const upb_msgdef* def) {
    return upb_downcast_msgdef_mutable(check_notfrozen((const upb_def*)def));
}

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
    zend_object_std_init(&intern->std, name##_type TSRMLS_CC);          \
    return_value.handle = zend_objects_store_put(                       \
        intern, (zend_objects_store_dtor_t)zend_objects_destroy_object, \
        name##_free, NULL TSRMLS_CC);                                   \
    return_value.handlers = zend_get_std_object_handlers();             \
    return return_value;                                                \
  }

#define DEFINE_SELF(type, var, php_var) type *var = php_to_##type(php_var)

// -----------------------------------------------------------------------------
// DescriptorPool
// -----------------------------------------------------------------------------

// Global singleton DescriptorPool. The user is free to create others, but this
// is used by generated code.
// VALUE generated_pool;

static zend_function_entry DescriptorPool_methods[] = {
  PHP_ME(DescriptorPool, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(DescriptorPool, add, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(DescriptorPool, build, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(DescriptorPool, search, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

DEFINE_CLASS(DescriptorPool, "Google\\Protobuf\\DescriptorPool");

PHP_METHOD(DescriptorPool, __construct) {
  DescriptorPool* intern = zend_object_store_get_object(getThis() TSRMLS_CC);
  intern->symtab = upb_symtab_new(&intern->symtab);
}

void DescriptorPool_free(void *object TSRMLS_DC) {
  DescriptorPool *descriptor_pool = (DescriptorPool *)object;
  efree(descriptor_pool);
}

static void add_descriptor_to_pool(DescriptorPool* self,
                                   Descriptor* descriptor) {
  CHECK_UPB(
      upb_symtab_add(self->symtab, (upb_def**)&descriptor->msgdef, 1,
                     NULL, &status),
      "Adding Descriptor to DescriptorPool failed");
}

PHP_METHOD(DescriptorPool, add) {
  DEFINE_SELF(DescriptorPool, self, getThis());
  zval *def = NULL;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &def) == FAILURE) {
    return;
  }
  add_descriptor_to_pool(self, php_to_Descriptor(def));
}

PHP_METHOD(DescriptorPool, build) {
  zval* builder;
  MAKE_STD_ZVAL(builder);
  object_init_ex(builder, Builder_type);
  CALL_METHOD1(Builder, finalize_to_pool, return_value, builder, getThis());
}

PHP_METHOD(DescriptorPool, search) {
  DEFINE_SELF(DescriptorPool, self, getThis());
  char *name = NULL;
  int str_len;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &str_len) ==
      FAILURE) {
    return;
  }
  const upb_def* def = upb_symtab_lookup(self->symtab, name);
  if (!def) {
    ZVAL_NULL(return_value);
  } else {
    ZVAL_ZVAL(return_value, get_def_obj(def), 0, 0);
  }
}

// -----------------------------------------------------------------------------
// Descriptor
// -----------------------------------------------------------------------------

static zend_function_entry Descriptor_methods[] = {
  PHP_ME(Descriptor, name_set, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Descriptor, __construct, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

DEFINE_CLASS(Descriptor, "Google\\Protobuf\\Descriptor");

PHP_METHOD(Descriptor, __construct) {
  Descriptor* intern = zend_object_store_get_object(getThis() TSRMLS_CC);
  intern->msgdef = upb_msgdef_new(&intern->msgdef);
}

void Descriptor_free(void *object TSRMLS_DC) {
  Descriptor *descriptor = (Descriptor *)object;
  efree(descriptor);
}

PHP_METHOD(Descriptor, name_set) {
  DEFINE_SELF(Descriptor, self, getThis());
  char *name = NULL;
  int str_len;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &str_len) ==
      FAILURE) {
    return;
  }
  upb_msgdef* mut_def = check_msg_notfrozen(self->msgdef);
  CHECK_UPB(
      upb_msgdef_setfullname(mut_def, name, &status),
      "Error setting Descriptor name");
  RETURN_NULL();
}

// -----------------------------------------------------------------------------
// MessageBuilderContext
// -----------------------------------------------------------------------------

static zend_function_entry MessageBuilderContext_methods[] = {
    PHP_ME(MessageBuilderContext, __construct, NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

DEFINE_CLASS(MessageBuilderContext,
             "Google\\Protobuf\\Internal\\MessageBuilderContext");

PHP_METHOD(MessageBuilderContext, __construct) {
  MessageBuilderContext *intern =
      zend_object_store_get_object(getThis() TSRMLS_CC);
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "OO",
                            &intern->descriptor, Descriptor_type,
                            &intern->builder, Builder_type) == FAILURE) {
    return;
  }
}

void MessageBuilderContext_free(void *object TSRMLS_DC) {
  MessageBuilderContext *descriptor = (MessageBuilderContext *)object;
  efree(descriptor);
}

// static VALUE msgdef_add_field(zval* msgdef,
//                               const char* label, zval* name,
//                               zval* type, zval* number,
//                               VALUE type_class) {
//   VALUE fielddef = rb_class_new_instance(0, NULL, cFieldDescriptor);
//   VALUE name_str = rb_str_new2(rb_id2name(SYM2ID(name)));

//   rb_funcall(fielddef, rb_intern("label="), 1, ID2SYM(rb_intern(label)));
//   rb_funcall(fielddef, rb_intern("name="), 1, name_str);
//   rb_funcall(fielddef, rb_intern("type="), 1, type);
//   rb_funcall(fielddef, rb_intern("number="), 1, number);

//   if (type_class != Qnil) {
//     if (TYPE(type_class) != T_STRING) {
//       rb_raise(rb_eArgError, "Expected string for type class");
//     }
//     // Make it an absolute type name by prepending a dot.
//     type_class = rb_str_append(rb_str_new2("."), type_class);
//     rb_funcall(fielddef, rb_intern("submsg_name="), 1, type_class);
//   }

//   rb_funcall(msgdef, rb_intern("add_field"), 1, fielddef);
//   return fielddef;
// }

// PHP_METHOD(MessageBuilderContext, optional) {
//   DEFINE_SELF(MessageBuilderContext, self, _self);
//   VALUE name, type, number, type_class;

//   if (argc < 3) {
//     rb_raise(rb_eArgError, "Expected at least 3 arguments.");
//   }
//   name = argv[0];
//   type = argv[1];
//   number = argv[2];
//   type_class = (argc > 3) ? argv[3] : Qnil;

//   return msgdef_add_field(self->descriptor, "optional",
//                           name, type, number, type_class);
// }

// -----------------------------------------------------------------------------
// Builder
// -----------------------------------------------------------------------------

static zend_function_entry Builder_methods[] = {
  PHP_ME(Builder, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Builder, add_message, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Builder, finalize_to_pool, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

DEFINE_CLASS(Builder, "Google\\Protobuf\\Internal\\Builder");

PHP_METHOD(Builder, __construct) {
  Builder *intern = zend_object_store_get_object(getThis() TSRMLS_CC);
  MAKE_STD_ZVAL(intern->pending_list);
  array_init(intern->pending_list);
}

void Builder_free(void *object TSRMLS_DC) {
  Builder *descriptor = (Builder *)object;
  efree(descriptor);
}

static void validate_msgdef(const upb_msgdef* msgdef) {
  // Verify that no required fields exist. proto3 does not support these.
  upb_msg_field_iter it;
  for (upb_msg_field_begin(&it, msgdef);
       !upb_msg_field_done(&it);
       upb_msg_field_next(&it)) {
    const upb_fielddef* field = upb_msg_iter_field(&it);
    if (upb_fielddef_label(field) == UPB_LABEL_REQUIRED) {
      zend_throw_exception(zend_exception_get_default(TSRMLS_C),
                           "Required fields are unsupported in proto3.",
                           0 TSRMLS_CC);
    }
  }
}

PHP_METHOD(Builder, add_message) {
  DEFINE_SELF(Builder, self, getThis());
  zval** descriptor = emalloc(sizeof(zval*));
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "O",
                            descriptor, Descriptor_type) == FAILURE) {
    return;
  }
  add_next_index_zval(self->pending_list, *descriptor);
}

PHP_METHOD(Builder, finalize_to_pool) {
  DEFINE_SELF(Builder, self, getThis());

  zval *pool_php = NULL;
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                            "O", &pool_php, *DescriptorPool_type) == FAILURE) {
    return;
  }
  DescriptorPool* pool = php_to_DescriptorPool(pool_php);
  self->defs = emalloc(sizeof(upb_def *) * Z_ARRVAL_SIZE_P(self->pending_list));

  int i = 0;
  Bucket *entry = Z_ARRVAL_BEGIN_P(self->pending_list);
  while (entry != NULL) {
    zval *def_php = *(zval **)entry->pData;
    php_to_Descriptor(def_php)->msgdef;
    self->defs[i] = (upb_def *)php_to_Descriptor(def_php)->msgdef;
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

  pool->symtab;
  self->defs;
  self->pending_list;
  CHECK_UPB(upb_symtab_add(pool->symtab, (upb_def **)self->defs,
                           Z_ARRVAL_SIZE_P(self->pending_list), NULL, &status),
            "Unable to add defs to DescriptorPool");

  i = 0;
  entry = Z_ARRVAL_BEGIN_P(self->pending_list);
  while (entry != NULL) {
    add_def_obj(self->defs[i], *(zval **)entry->pData);
    Z_BUCKET_NEXT_PP(&entry);
    i++;
  }

  array_init(self->pending_list);
  RETURN_NULL();
}
