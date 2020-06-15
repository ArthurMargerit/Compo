#include <ostream>

#include <string>
class MyString{
public:
  std::string str;
};

bool operator==(const MyString &a, const MyString &b);
std::ostream &operator<<(std::ostream &os, const MyString &c);
std::istream &operator>>(std::istream &is, MyString &c);
