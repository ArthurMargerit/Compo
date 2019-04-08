#include "Data/Types.hpp"

#include "Data/Struct_AAC.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const AAC&  c)
{
  os << "{"
     << "aac:"<< c.aac
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, AAC& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.aac ;
  is.ignore(1, '}');

  return is;
}


  AAC::AAC(int p_aac)
  :
    aac(p_aac)
  {

  }


  AAC::AAC()
  :
    aac(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
int
AAC::get_aac() const {
    return this->aac;
 }

void
AAC::set_aac(const int value) {
  this->aac = value;
}

