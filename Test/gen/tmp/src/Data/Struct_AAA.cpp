#include "Data/Types.hpp"

#include "Data/Struct_AAA.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AAA&  c)
{
  os << "{"
     << "a3:"<< c.a3
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AAA& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a3 ;
  is.ignore(1, '}');

  return is;
}


  AAA::AAA(int p_a3)
  :
    a3(p_a3)
  {

  }


  AAA::AAA()
  :
    a3(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AAA::get_a3() const {
    return this->a3;
 }

void
AAA::set_a3(const int value) {
  this->a3 = value;
}

