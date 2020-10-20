#pragma once

#include <istream>
#include <ostream>

#include <array>

template <typename F, typename S> using Pair = std::pair<F, S>;

namespace std {

template <typename F, typename S>
std::ostream &operator<<(std::ostream &os, const Pair<F, S> &t) {
  os << "<" <<t.first << ","<< t.second<< ">";
  return os;
}

template <typename F, typename S>
std::istream &operator>>(std::istream &is, Pair<F, S> & t) {
  if(is.peek() != '<') {
    return is;
  }
  is.get();

  is >> t.first;

  if(is.peek() != ',') {
    return is;
  }
  is.get();

  is >> t.second;

  if(is.peek() != '>') {
    return is;
  }
  is.get();

  return is;
}
} // namespace std
