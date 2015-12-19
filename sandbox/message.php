<?php

namespace Google\Protobuf;

class Message {
  public function __get($field) {
    if (isset($fields[$field])) {
      return $this->fields[$field];
    }
  }
}

?>
