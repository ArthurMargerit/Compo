#pragma once
#include "json.hpp"
#include <string>
#include "Serialization_context.hpp"
namespace CompoMe {
class Struct;

class Function_json_recv {
private:
  nlohmann::json data;
  Serialization_context_import ctx;

public:
  nlohmann::json &get_data();

  virtual void pull() = 0;
  virtual void end() = 0;

  std::string get_function();
  nlohmann::json &get_params();
  Serialization_context_import &get_ctx();
};

void import_struct(Function_json_recv &s, Struct &e);
} // namespace CompoMe
