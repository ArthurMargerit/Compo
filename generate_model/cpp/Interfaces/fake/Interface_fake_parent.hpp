#pragma once

// class Function_stream;
// class Return_stream;

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Fake {
public:

  Return_stream& get_i() const {
    return i;
  }

  Function_stream& get_o() const {
    return o;
  }

  Fake(Function_stream& o,
       Return_stream& i);

  Fake();

  virtual ~Fake();

private:
  Function_stream& o;
  Return_stream& i;
};

