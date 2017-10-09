static void init_file_timestamp() {
  static bool is_initialized = false;
  if (is_initialized) return;
  init_generated_pool_once(TSRMLS_C);
  const char* generated_file =
      "0ae7010a1f676f6f676c652f70726f746f6275662f74696d657374616d70"
      "2e70726f746f120f676f6f676c652e70726f746f627566222b0a0954696d"
      "657374616d70120f0a077365636f6e6473180120012803120d0a056e616e"
      "6f73180220012805427e0a13636f6d2e676f6f676c652e70726f746f6275"
      "66420e54696d657374616d7050726f746f50015a2b6769746875622e636f"
      "6d2f676f6c616e672f70726f746f6275662f7074797065732f74696d6573"
      "74616d70f80101a20203475042aa021e476f6f676c652e50726f746f6275"
      "662e57656c6c4b6e6f776e5479706573620670726f746f33";
  char* binary;
  int binary_len;
  hex_to_binary(generated_file, &binary, &binary_len);
  internal_add_generated_file(binary, binary_len, generated_pool TSRMLS_CC);
  FREE(binary);
  is_initialized = true;
}

