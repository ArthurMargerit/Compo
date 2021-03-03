#pragma once
#include "json.hpp"
#include "Serialization_context.hpp"

namespace CompoMe {
class Struct;
class Return_json_send {
private:
  nlohmann::json data;
  Serialization_context_export ctx;
public:

  nlohmann::json &get_data();
  Serialization_context_export &get_ctx();

  virtual void start() = 0;
  virtual void send() = 0;
};

void export_struct(Return_json_send &s, Struct &e);
} // namespace CompoMe
