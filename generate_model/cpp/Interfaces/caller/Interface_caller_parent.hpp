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
  bool call(Function_stream& is, Return_stream& os)=0;
  
  virtual
  bool call(std::string& name_function, Function_stream& is, Return_stream& os)=0;
};


