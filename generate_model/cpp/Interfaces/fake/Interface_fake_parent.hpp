#pragma once

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

static Function_string_stream trash_o;
static Return_string_stream trash_i;

class Fake {
public:
  Return_stream &get_i() const { return i;}
  Function_stream &get_o() const { return o;}

  Fake(Function_stream &o, Return_stream &i);
  Fake() : Fake(trash_o, trash_i) {};
  virtual ~Fake();

private:
  Function_stream &o;
  Return_stream &i;
};
