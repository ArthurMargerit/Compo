#include "Data/Types.hpp"

#include "Data/Struct_Dot.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const Dot&  c)
{
  os << "{"
     << "h:"<< c.h<<","
     << "w:"<< c.w
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, Dot& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.h ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.w ;
  is.ignore(1, '}');

  return is;
}


  Dot::Dot(int p_h,int p_w)
  :
    h(p_h),
    w(p_w)
  {

  }


  Dot::Dot()
  :
    h(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
    w(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
