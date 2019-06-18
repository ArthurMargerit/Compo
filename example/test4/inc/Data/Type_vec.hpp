#pragma once

#include <vector>

template <typename T> using vec = std::vector<T>;

#include <istream>
#include <ostream>

template <typename T>
std::ostream &operator<<(std::ostream &os, const vec<T> &) {
  return os;
}

template <typename T> std::istream &operator>>(std::istream &is, vec<T> &) {
  return is;
}
