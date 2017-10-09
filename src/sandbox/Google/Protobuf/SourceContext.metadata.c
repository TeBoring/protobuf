static void init_file_source_context() {
  static bool is_initialized = false;
  if (is_initialized) return;
  init_generated_pool_once(TSRMLS_C);
  const char* generated_file =
      "0afb010a24676f6f676c652f70726f746f6275662f736f757263655f636f"
      "6e746578742e70726f746f120f676f6f676c652e70726f746f6275662222"
      "0a0d536f75726365436f6e7465787412110a0966696c655f6e616d651801"
      "200128094295010a13636f6d2e676f6f676c652e70726f746f6275664212"
      "536f75726365436f6e7465787450726f746f50015a41676f6f676c652e67"
      "6f6c616e672e6f72672f67656e70726f746f2f70726f746f6275662f736f"
      "757263655f636f6e746578743b736f757263655f636f6e74657874a20203"
      "475042aa021e476f6f676c652e50726f746f6275662e57656c6c4b6e6f77"
      "6e5479706573620670726f746f33";
  char* binary;
  int binary_len;
  hex_to_binary(generated_file, &binary, &binary_len);
  internal_add_generated_file(binary, binary_len, generated_pool TSRMLS_CC);
  FREE(binary);
  is_initialized = true;
}

