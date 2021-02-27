#pragma once

#include <json.hpp>

namespace CompoMe {

class Struct;

class Return_json_recv {
public:
  virtual nlohmann::json &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
};

} // namespace CompoMe

template <typename T>
CompoMe::Return_json_recv &operator>>(CompoMe::Return_json_recv &s, T &e) {
  s.get_si().get_to(e);
  return s;
}

CompoMe::Return_json_recv &operator>>(CompoMe::Return_json_recv &s, CompoMe::Struct &e);
