#include "Data/Types.hpp"

#include "Data/Struct_AAAAA.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AAAAA&  c)
{
  os << "{"
     << "a5:"<< c.a5
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AAAAA& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a5 ;
  is.ignore(1, '}');

  return is;
}


  AAAAA::AAAAA(int p_a5)
  :
    a5(p_a5)
  {

  }


  AAAAA::AAAAA()
  :
    a5(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AAAAA::get_a5() const {
    return this->a5;
 }

void
AAAAA::set_a5(const int value) {
  this->a5 = value;
}

