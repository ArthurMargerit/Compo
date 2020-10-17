#pragma once

#include <istream>
#include <ostream>

#include <vector>

template <typename T> using Vec = std::vector<T>;

namespace std {

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vec<T> &t) {
  os << "[";
  bool f = false;
  for (const T&i_t : t) {
    if(f){
      os << ",";
  }else{
    f = true;
  }

    os << i_t ;
  }
  os<< "]";
  return os;
}

template <typename T> std::istream &operator>>(std::istream &is, Vec<T> &t) {
  t = Vec<T>();

  if(is.peek() != '[') {
    return is;
  }
  is.get();

  if(is.peek() == ']') {
    is.get();
    return is;
  }

  do {
    T a;
    is >> a;
    t.push_back(a);
  } while(is.get() != ']');

  return is;
}
} // namespace std
