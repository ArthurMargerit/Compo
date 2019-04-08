#include "Data/Types.hpp"

#include "Data/Struct_AAAAAA.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AAAAAA&  c)
{
  os << "{"
     << "a6:"<< c.a6
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AAAAAA& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a6 ;
  is.ignore(1, '}');

  return is;
}


  AAAAAA::AAAAAA(int p_a6)
  :
    a6(p_a6)
  {

  }


  AAAAAA::AAAAAA()
  :
    a6(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AAAAAA::get_a6() const {
    return this->a6;
 }

void
AAAAAA::set_a6(const int value) {
  this->a6 = value;
}

