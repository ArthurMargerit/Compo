#pragma once

#include <map>

template <typename K, typename V> using map = std::map<K, V>;

#include <istream>
#include <ostream>

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const map<K, V> &) {
  return os;
}

template <typename K, typename V>
std::istream &operator>>(std::istream &is, map<K, V> &) {
  return is;
}
