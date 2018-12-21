
#include "Data/Struct.hpp"

std::ostream& operator<<(std::ostream& os, const Struct* c)
{
  os << "*"<< &c;
  return os;
}