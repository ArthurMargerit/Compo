#include "MyString.hpp"
#include <iostream>
#include <sstream>
#include <string>

bool operator==(const MyString &a, const MyString &b) {
  return a.str == b.str;
}

std::ostream &operator<<(std::ostream &os, const MyString &c) {
  os << '"' << c.str << '"';
  return os;
}

std::istream &operator>>(std::istream &is, MyString &c) {
  if ('"' != is.peek()) {
    std::cin >> c.str;
    return is;
  }

  is.get();
  std::getline(is, c.str, '"');
  return is;
}
