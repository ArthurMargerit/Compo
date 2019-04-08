#pragma once

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"
#include <iostream>

class Caller {
public:
  Caller();
  virtual ~Caller();

  virtual bool call(Function_stream &is, Return_stream &os) = 0;
};

namespace std {
Function_stream &getline(Function_stream &is, string &str, char delim);
Function_stream &getline(Function_stream &is, string &str);
Return_stream &getline(Return_stream &is, string &str, char delim);
Return_stream &getline(Return_stream &is, string &str);
} // namespace std