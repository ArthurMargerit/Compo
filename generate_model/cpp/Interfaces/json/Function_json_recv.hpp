#pragma once
#include "json.hpp"
#include <string>

namespace CompoMe {
class Struct;
class Serialization_context_import;

class Function_json_recv {
public:
  virtual nlohmann::json &get_si() = 0;
  virtual void pull() = 0;
  virtual void end() = 0;
  virtual std::string get_function() = 0;
  virtual nlohmann::json &get_params() = 0;
  virtual Serialization_context_import &get_ctx() = 0;
};

void import_struct(Function_json_recv &s, Struct &e);
} // namespace CompoMe

template <typename T>
CompoMe::Function_json_recv &operator>>(CompoMe::Function_json_recv &s, T &e) {
  s.get_si().get_to(e);
  return s;
}
