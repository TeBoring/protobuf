static void init_file_empty() {
  static bool is_initialized = false;
  if (is_initialized) return;
  init_generated_pool_once(TSRMLS_C);
  const char* generated_file =
      "0ab7010a1b676f6f676c652f70726f746f6275662f656d7074792e70726f"
      "746f120f676f6f676c652e70726f746f62756622070a05456d7074794276"
      "0a13636f6d2e676f6f676c652e70726f746f627566420a456d7074795072"
      "6f746f50015a276769746875622e636f6d2f676f6c616e672f70726f746f"
      "6275662f7074797065732f656d707479f80101a20203475042aa021e476f"
      "6f676c652e50726f746f6275662e57656c6c4b6e6f776e54797065736206"
      "70726f746f33";
  char* binary;
  int binary_len;
  hex_to_binary(generated_file, &binary, &binary_len);
  internal_add_generated_file(binary, binary_len, generated_pool TSRMLS_CC);
  FREE(binary);
  is_initialized = true;
}

