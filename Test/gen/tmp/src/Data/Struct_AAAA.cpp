#include "Data/Types.hpp"

#include "Data/Struct_AAAA.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AAAA&  c)
{
  os << "{"
     << "a4:"<< c.a4
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AAAA& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a4 ;
  is.ignore(1, '}');

  return is;
}


  AAAA::AAAA(int p_a4)
  :
    a4(p_a4)
  {

  }


  AAAA::AAAA()
  :
    a4(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AAAA::get_a4() const {
    return this->a4;
 }

void
AAAA::set_a4(const int value) {
  this->a4 = value;
}

