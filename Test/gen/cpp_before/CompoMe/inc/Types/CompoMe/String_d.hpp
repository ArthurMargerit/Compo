#include <ostream>

#include <string>
namespace CompoMe {
class String {
public:
  String() : str("") {}
  String(std::string &p_str) : str(p_str) {}
  String(const char *p_str) : str(p_str) {}

  operator const std::string&() const { return this->str; }
  std::string str;
};

bool operator==(const CompoMe::String &a, const CompoMe::String &b);
std::ostream &operator<<(std::ostream &os, const CompoMe::String &c);
std::istream &operator>>(std::istream &is, CompoMe::String &c);
} // namespace CompoMe
