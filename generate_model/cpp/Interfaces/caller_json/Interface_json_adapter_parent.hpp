
#pragma once
#include <string>
#include "Serialization_context.hpp"

namespace CompoMe {
class Function_json_recv;
class Return_json_send;

class Caller_json {
public:
  Caller_json();
  virtual ~Caller_json();

  virtual bool call(CompoMe::Function_json_recv &,
                    CompoMe::Return_json_send &) = 0;

  virtual bool call(std::string &name_function, Function_json_recv &,
                    Return_json_send &) = 0;

  virtual void introspection(std::ostream &ss) = 0;
};

} // namespace CompoMe
