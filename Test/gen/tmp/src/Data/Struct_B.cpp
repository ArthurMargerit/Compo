#include "Data/Types.hpp"

#include "Data/Struct_B.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const B&  c)
{
  os << "{"
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, B& c)
{
  is.ignore(100, '{');
  is.ignore(1, '}');

  return is;
}



  B::B()
  
  {
  }

