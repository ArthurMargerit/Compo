#pragma once
#include "json.hpp"

namespace CompoMe {
class Struct;

class Serialization_context_export;

class Return_json_send {
public:
  virtual nlohmann::json &get_so() = 0;

  template<typename T>
  void set_return(T& t) {
    this->get_so()["result"] = t;
    return;
  }

  virtual Serialization_context_export &get_ctx() = 0;

  virtual void start() = 0;
  virtual void send() = 0;
};

void export_struct(Return_json_send &s, Struct &e);
} // namespace CompoMe

template <typename T>
CompoMe::Return_json_send &operator<<(CompoMe::Return_json_send &s, const T &e) {
  s.get_so() = e;
  return s;
}
