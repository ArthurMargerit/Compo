#pragma once

#include <ostream>
#include <string>

namespace CompoMe {
class String_d {
public:
  String_d() : str("") {}
  String_d(std::string &p_str) : str(p_str) {}
  String_d(const char *p_str) : str(p_str) {}

  operator const std::string&() const { return this->str; }
  std::string str;
};

bool operator==(const CompoMe::String_d &a, const CompoMe::String_d &b);
std::ostream &operator<<(std::ostream &os, const CompoMe::String_d &c);
bool operator<( const CompoMe::String_d &b, const CompoMe::String_d & a);
std::istream &operator>>(std::istream &is, CompoMe::String_d &c);
} // namespace CompoMe
