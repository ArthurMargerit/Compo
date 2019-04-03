#pragma once

#include <ostream>
#include <istream>

struct Struct
{

};



template<typename N>
std::istream& operator>>(std::istream& is, N* c)
{
  is.ignore(1, '*');
  is >> *c;
  return is;
}
