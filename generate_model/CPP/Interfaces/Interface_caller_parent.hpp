#pragma once

#include <iostream>

class Caller
{
public:
  Caller();
  virtual ~Caller();

  virtual
  bool call(std::istream& is, std::ostream& os)=0;
};
