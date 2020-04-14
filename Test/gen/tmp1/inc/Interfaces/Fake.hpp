#pragma once

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Fake {
public:
  Fake(Function_stream &o, Return_stream &i);
  virtual ~Fake();

  Return_stream &get_i() const { return i; }
  Function_stream &get_o() const { return o; }

private:
  Function_stream &o;
  Return_stream &i;
};
