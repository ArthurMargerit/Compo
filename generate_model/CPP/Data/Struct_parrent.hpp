
#pragma once



struct Struct1
{
};


std::ostream& operator<<(std::ostream& os, const Struct1* c)
{
  os << "*"<< &c;
  return os;
}
