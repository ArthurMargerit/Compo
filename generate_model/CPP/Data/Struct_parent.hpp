#pragma once

#include <ostream>
#include <istream>

struct Struct
{
  virtual void to_stream(std::ostream& ) const =0;
};
std::string get_type(std::istream &is);

std::istream &operator>>(std::istream &is, Struct *&c);
std::ostream& operator<<(std::ostream& os, const Struct* c);


// template<typename N>
// std::istream& operator>>(std::istream& is, N* c)
// {
//   is.ignore(1, '*');
//   is >> *c;
//   return is;
// }
