#include "Data/Types.hpp"

#include "Data/Struct_Pos.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const Pos&  c)
{
  os << "{"
     << "x:"<< c.x<<","
     << "y:"<< c.y
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, Pos& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.x ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.y ;
  is.ignore(1, '}');

  return is;
}


  Pos::Pos(int p_x,int p_y)
  :
    x(p_x),
    y(p_y)
  {

  }


  Pos::Pos()
  :
    x(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
    y(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
Pos::get_x() const {
    return this->x;
 }

void
Pos::set_x(const int value) {
  this->x = value;
}
int
Pos::get_y() const {
    return this->y;
 }

void
Pos::set_y(const int value) {
  this->y = value;
}

