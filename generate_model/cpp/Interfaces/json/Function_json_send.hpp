#pragma once
#include "Serialization_context.hpp"
#include "json.hpp"
#include <string>

namespace CompoMe {
class Struct;

class Function_json_send {
  nlohmann::json data;
  Serialization_context_export ctx;
public :
  nlohmann::json &get_data();
  Serialization_context_export& get_ctx();
  void set_function(std::string str);
  virtual void start() = 0;
  virtual void send() = 0;
};
}
