#include "Data/Types.hpp"

#include "Data/Struct_AB.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AB&  c)
{
  os << "{"
     << "ab:"<< c.ab
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AB& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.ab ;
  is.ignore(1, '}');

  return is;
}


  AB::AB(int p_ab)
  :
    ab(p_ab)
  {

  }


  AB::AB()
  :
    ab(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AB::get_ab() const {
    return this->ab;
 }

void
AB::set_ab(const int value) {
  this->ab = value;
}

