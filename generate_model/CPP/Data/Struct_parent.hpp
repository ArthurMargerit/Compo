#pragma once

#include <ostream>
#include <istream>

struct Struct
{
  virtual void to_stream(std::ostream& ) const =0;
};



// template<typename N>
// std::istream& operator>>(std::istream& is, N* c)
// {
//   is.ignore(1, '*');
//   is >> *c;
//   return is;
// }
