#include "Data/Types.hpp"

#include "Data/Struct_AA.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AA&  c)
{
  os << "{"
     << "a2:"<< c.a2
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AA& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.a2 ;
  is.ignore(1, '}');

  return is;
}


  AA::AA(int p_a2)
  :
    a2(p_a2)
  {

  }


  AA::AA()
  :
    a2(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AA::get_a2() const {
    return this->a2;
 }

void
AA::set_a2(const int value) {
  this->a2 = value;
}

