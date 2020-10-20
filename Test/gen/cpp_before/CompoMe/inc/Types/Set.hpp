#pragma once

#include <istream>
#include <ostream>

#include <set>

template <typename T> using Set = std::set<T>;

namespace std {

template <typename T>
std::ostream &operator<<(std::ostream &os, const Set<T> &p) {
  os << "{";
  bool f= false;
  for (const T& i_t : p) {
    if(f){
      os << ",";
    }else{
      f = true;
    }

    os << i_t ;
  }

  os << "}";
  return os;
}

template <typename T> std::istream &operator>>(std::istream &is, Set<T> &t) {
  t = Set<T>();

  if(is.peek() != '{') {
    return is;
  }
  is.get();

  if(is.peek() == '}') {
    is.get();
    return is;
  }

  do {
    T a;
    is >> a;
    t.insert(a);
  } while(is.get() != '}');

  return is;
}
} // namespace std
