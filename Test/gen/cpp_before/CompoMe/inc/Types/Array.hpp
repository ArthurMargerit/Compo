#pragma once

#include <istream>
#include <ostream>

#include <array>

template <typename DATA, unsigned long int NB>
using Array = std::array<DATA, NB>;

namespace std {

template <typename DATA, unsigned long int NB>
std::ostream &operator<<(std::ostream &os, const Array<DATA, NB> &p) {
  os<<"[";

  if (NB>=1) {
  for (unsigned long int i = 0; i < NB-1; ++i) {
    os << p[i] << ",";
  }
  os <<  p[NB-1];
 }
     os << "]";

  return os;
}

template <typename DATA, unsigned long int NB>
std::istream &operator>>(std::istream &is, Array<DATA, NB> &p) {
  if (is.peek() != '[') {
    return is;
  }
  is.get();

  if (NB==0) {
    is.get();
    return is;
  }

  unsigned long int i = 0;
  do {
    is >> p[i++];
  } while(is.get() == ',' && i <= NB);

  return is;
}
} // namespace std
