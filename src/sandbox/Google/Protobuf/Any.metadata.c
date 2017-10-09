static void init_file_any() {
  static bool is_initialized = false;
  if (is_initialized) return;
  init_generated_pool_once(TSRMLS_C);
  const char* generated_file =
      "0acd010a19676f6f676c652f70726f746f6275662f616e792e70726f746f"
      "120f676f6f676c652e70726f746f62756622260a03416e7912100a087479"
      "70655f75726c180120012809120d0a0576616c756518022001280c426f0a"
      "13636f6d2e676f6f676c652e70726f746f6275664208416e7950726f746f"
      "50015a256769746875622e636f6d2f676f6c616e672f70726f746f627566"
      "2f7074797065732f616e79a20203475042aa021e476f6f676c652e50726f"
      "746f6275662e57656c6c4b6e6f776e5479706573620670726f746f33";
  char* binary;
  int binary_len;
  hex_to_binary(generated_file, &binary, &binary_len);
  internal_add_generated_file(binary, binary_len, generated_pool TSRMLS_CC);
  FREE(binary);
  is_initialized = true;
}

