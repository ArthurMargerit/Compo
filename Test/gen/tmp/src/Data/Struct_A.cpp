#include "Data/Types.hpp"

#include "Data/Struct_A.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const A&  c)
{
  os << "{"
     << "a1:"<< c.a1
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, A& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a1 ;
  is.ignore(1, '}');

  return is;
}


  A::A(int p_a1)
  :
    a1(p_a1)
  {

  }


  A::A()
  :
    a1(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
A::get_a1() const {
    return this->a1;
 }

void
A::set_a1(const int value) {
  this->a1 = value;
}

