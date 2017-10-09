static void init_file_duration() {
  static bool is_initialized = false;
  if (is_initialized) return;
  init_generated_pool_once(TSRMLS_C);
  const char* generated_file =
      "0ae3010a1e676f6f676c652f70726f746f6275662f6475726174696f6e2e"
      "70726f746f120f676f6f676c652e70726f746f627566222a0a0844757261"
      "74696f6e120f0a077365636f6e6473180120012803120d0a056e616e6f73"
      "180220012805427c0a13636f6d2e676f6f676c652e70726f746f62756642"
      "0d4475726174696f6e50726f746f50015a2a6769746875622e636f6d2f67"
      "6f6c616e672f70726f746f6275662f7074797065732f6475726174696f6e"
      "f80101a20203475042aa021e476f6f676c652e50726f746f6275662e5765"
      "6c6c4b6e6f776e5479706573620670726f746f33";
  char* binary;
  int binary_len;
  hex_to_binary(generated_file, &binary, &binary_len);
  internal_add_generated_file(binary, binary_len, generated_pool TSRMLS_CC);
  FREE(binary);
  is_initialized = true;
}

