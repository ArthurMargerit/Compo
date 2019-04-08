#include "Data/Types.hpp"

#include "Data/Struct_AC.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AC&  c)
{
  os << "{"
     << "ac:"<< c.ac
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AC& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.ac ;
  is.ignore(1, '}');

  return is;
}


  AC::AC(int p_ac)
  :
    ac(p_ac)
  {

  }


  AC::AC()
  :
    ac(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AC::get_ac() const {
    return this->ac;
 }

void
AC::set_ac(const int value) {
  this->ac = value;
}

