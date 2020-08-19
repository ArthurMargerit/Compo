#include <ostream>

#include <string>
namespace CompoMe {
class String {
public:
  std::string str;
};

bool operator==(const CompoMe::String &a, const CompoMe::String &b);
std::ostream &operator<<(std::ostream &os, const CompoMe::String &c);
std::istream &operator>>(std::istream &is, CompoMe::String &c);
} // namespace CompoMe
