#pragma once

#include <iostream>
#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller
{
public:
  Caller();
  virtual ~Caller();

  virtual
  bool call(function_stream& is, Return_stream& os)=0;
};
