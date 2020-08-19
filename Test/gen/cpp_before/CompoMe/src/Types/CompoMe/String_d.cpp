#include "Types/CompoMe/String_d.hpp"

#include <sstream>
#include <string>

// TODO: escape wrong char

namespace CompoMe {

bool operator==(const CompoMe::String &a, const CompoMe::String &b) {
  return a.str == b.str;
}

std::ostream &operator<<(std::ostream &os, const CompoMe::String &c) {
  os << '"' << c.str << '"';
  return os;
}

std::istream &operator>>(std::istream &is, CompoMe::String &c) {
  if ('"' != is.peek()) {
    return is;
  }

  is.get();
  std::getline(is, c.str, '"');
  return is;
}

} // namespace CompoMe
