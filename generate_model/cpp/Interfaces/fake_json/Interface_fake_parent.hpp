#pragma once

#include "Interfaces/Function_json_send.hpp"
#include "Interfaces/Return_json_recv.hpp"

namespace CompoMe {

class Fake_json {
public:
  Return_json_recv &get_i() const { return a_i; }
  Function_json_send &get_o() const { return a_o; }

  Fake_json(Function_json_send &out, Return_json_recv &in);
  virtual ~Fake_json();

private:
  Function_json_send &a_o;
  Return_json_recv &a_i;
};

} // namespace CompoMe
