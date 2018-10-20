#include "Data/Types.hpp"

#include "Data/Struct_S1.hpp"

#include <ostream>
#include <istream>


std::ostream& operator<<(std::ostream& os, const S1&  c)
{
  os << "{"
     << "a1:"<< c.a1<<","
     << "a2:"<< c.a2<<","
     << "a3:"<< c.a3
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, S1& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a1 ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.a2 ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.a3 ;
  is.ignore(1, '}');

  return is;
}


  S1::S1(int p_a1,int p_a2,int p_a3)
  :
    a1(p_a1),
    a2(p_a2),
    a3(p_a3)
  {

  }


  S1::S1()
  :
    a1(),
    a2(),
    a3()
  {
  }
