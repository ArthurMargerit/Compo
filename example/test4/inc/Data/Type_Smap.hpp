#pragma once

#include "Data/Type_map.hpp"

template <typename V> using Smap = map<std::string, V>;

#include <istream>
#include <ostream>

template <typename V>
std::ostream &operator<<(std::ostream &os, const Smap<V> &) {
  return os;
}

template <typename V> std::istream &operator>>(std::istream &is, Smap<V> &) {
  return is;
}
