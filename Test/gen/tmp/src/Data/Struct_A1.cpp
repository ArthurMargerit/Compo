#include "Data/Types.hpp"

#include "Data/Struct_A1.hpp"

#include <ostream>
#include <istream>


std::ostream& operator<<(std::ostream& os, const A1&  c)
{
  os << "{"
     << "a:"<< c.a<<","
     << "b:"<< c.b
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, A1& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.b ;
  is.ignore(1, '}');

  return is;
}


  A1::A1(int p_a,int p_b)
  :
    a(p_a),
    b(p_b)
  {

  }


  A1::A1()
  :
    a(),
    b()
  {
  }
