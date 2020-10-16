#include "Types/CompoMe/String_d.hpp"

#include <sstream>
#include <string>

// TODO: escape wrong char

namespace CompoMe {

bool operator==(const CompoMe::String_d &a, const CompoMe::String_d &b) {
  return a.str == b.str;
}

std::ostream &operator<<(std::ostream &os, const CompoMe::String_d &c) {
  os << '"' << c.str << '"';
  return os;
}

std::istream &operator>>(std::istream &is, CompoMe::String_d &c) {
  if ('"' != is.peek()) {
    return is;
  }

  is.get();
  std::getline(is, c.str, '"');
  return is;
}

bool operator<( const CompoMe::String_d &b, const CompoMe::String_d & a) {
  return a.str < b.str;
}

} // namespace CompoMe
