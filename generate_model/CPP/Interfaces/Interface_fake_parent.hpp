#pragma once

// class Function_stream;
// class Return_stream;

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Fake {
public:
  Fake(Function_stream& o,
       Return_stream& i);

  Fake();

  virtual ~Fake();
protected:
  Function_stream& o;
  Return_stream& i;
};

