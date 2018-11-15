#include "Data/Types.hpp"

#include "Data/Struct_Empty.hpp"

#include <ostream>
#include <istream>


std::ostream& operator<<(std::ostream& os, const Empty&  c)
{
  os << "{"
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, Empty& c)
{
  is.ignore(100, '{');
  is.ignore(1, '}');

  return is;
}



  Empty::Empty()
  
  {
  }
