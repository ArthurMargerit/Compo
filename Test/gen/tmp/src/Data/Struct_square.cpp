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
    position(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
    Size(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
    Size2(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
    a(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
Pos
square::get_position() const {
    return this->position;
 }

void
square::set_position(const Pos value) {
  this->position = value;
}
Dot
square::get_Size() const {
    return this->Size;
 }

void
square::set_Size(const Dot value) {
  this->Size = value;
}
Dot
square::get_Size2() const {
    return this->Size2;
 }

void
square::set_Size2(const Dot value) {
  this->Size2 = value;
}
int
square::get_a() const {
    return this->a;
 }

void
square::set_a(const int value) {
  this->a = value;
}

