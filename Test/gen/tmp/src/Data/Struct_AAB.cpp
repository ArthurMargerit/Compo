#include "Data/Types.hpp"

#include "Data/Struct_AAB.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AAB&  c)
{
  os << "{"
     << "aab:"<< c.aab
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AAB& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.aab ;
  is.ignore(1, '}');

  return is;
}


  AAB::AAB(int p_aab)
  :
    aab(p_aab)
  {

  }


  AAB::AAB()
  :
    aab(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AAB::get_aab() const {
    return this->aab;
 }

void
AAB::set_aab(const int value) {
  this->aab = value;
}

