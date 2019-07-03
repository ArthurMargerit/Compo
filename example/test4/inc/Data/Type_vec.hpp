#pragma once

#include <vector>

template <typename T> using vec = std::vector<T>;

#include <istream>
#include <ostream>
#include <sstream>

template <typename T>
std::ostream &operator<<(std::ostream &os, const vec<T> &) {

  os << "[";
  int i = 0;
  int size = c.size();
  for (auto &v : c) {
    os << v;

    i++;
    if (i != size) {
      os << ",";
    }
  }
  os << "]";

  return os;
}

template <typename T> std::istream &operator>>(std::istream &is, vec<T> &) {
  char cc;

  is.get(cc);
  if (cc != '[') {
    throw "NOT a vec ";
  }

  std::stringstream s;

  while (true) {

    is.get(cc);

    if (cc == ']') {
      T t;
      s >> t;
      c.push_back(t);
      break;
    }

    if (cc == ',') {
      T t;
      s >> t;
      c.push_back(t);
      s.clear();
    } else {
      s.put(cc);
    }
  }

  return is;
}
