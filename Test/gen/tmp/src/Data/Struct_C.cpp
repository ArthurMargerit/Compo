#include "Data/Types.hpp"

#include "Data/Struct_C.hpp"

#include <ostream>
#include <istream>


std::ostream& operator<<(std::ostream& os, const C&  c)
{
  os << "{"
     << "a:"<< c.a<<","
     << "b:"<< c.b<<","
     << "c:"<< c.c
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, C& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.b ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.c ;
  is.ignore(1, '}');

  return is;
}


  C::C(int p_a,int p_b,int p_c)
  :
    a(p_a),
    b(p_b),
    c(p_c)
  {

  }


  C::C()
  :
    a(),
    b(),
    c()
  {
  }
