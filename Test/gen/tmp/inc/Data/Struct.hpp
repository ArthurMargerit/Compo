#pragma once

#include <istream>
#include <ostream>

struct Struct {};

template <typename N> std::istream &operator>>(std::istream &is, N *c) {
  is.ignore(1, '*');
  is >> *c;
  return is;
}