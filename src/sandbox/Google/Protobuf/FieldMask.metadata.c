static void init_file_field_mask() {
  static bool is_initialized = false;
  if (is_initialized) return;
  init_generated_pool_once(TSRMLS_C);
  const char* generated_file =
      "0ae3010a20676f6f676c652f70726f746f6275662f6669656c645f6d6173"
      "6b2e70726f746f120f676f6f676c652e70726f746f627566221a0a094669"
      "656c644d61736b120d0a0570617468731801200328094289010a13636f6d"
      "2e676f6f676c652e70726f746f627566420e4669656c644d61736b50726f"
      "746f50015a39676f6f676c652e676f6c616e672e6f72672f67656e70726f"
      "746f2f70726f746f6275662f6669656c645f6d61736b3b6669656c645f6d"
      "61736ba20203475042aa021e476f6f676c652e50726f746f6275662e5765"
      "6c6c4b6e6f776e5479706573620670726f746f33";
  char* binary;
  int binary_len;
  hex_to_binary(generated_file, &binary, &binary_len);
  internal_add_generated_file(binary, binary_len, generated_pool TSRMLS_CC);
  FREE(binary);
  is_initialized = true;
}

