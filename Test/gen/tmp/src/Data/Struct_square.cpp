#include "Data/Types.hpp"

#include "Data/Struct_square.hpp"

#include <ostream>
#include <istream>


std::ostream& operator<<(std::ostream& os, const square&  c)
{
  os << "{"
     << "position:"<< c.position<<","
     << "Size:"<< c.Size<<","
     << "Size2:"<< c.Size2<<","
     << "a:"<< c.a
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, square& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.position ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.Size ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.Size2 ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.a ;
  is.ignore(1, '}');

  return is;
}


  square::square(Pos p_position,Dot p_Size,Dot p_Size2,int p_a)
  :
    position(p_position),
    Size(p_Size),
    Size2(p_Size2),
    a(p_a)
  {

  }


  square::square()
  :
    position(),
    Size(),
    Size2(),
    a()
  {
  }
