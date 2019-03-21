#include "Data/Types.hpp"

#include "Data/Struct_A.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const A&  c)
{
  os << "{"
     << "a:"<< c.a
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, A& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a ;
  is.ignore(1, '}');

  return is;
}


  A::A(int p_a)
  :
    a(p_a)
  {

  }


  A::A()
  :
    a(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
A::get_a() const {
    return this->a;
 }

void
A::set_a(const int value) {
  this->a = value;
}

