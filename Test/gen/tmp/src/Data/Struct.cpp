
#include "Data/Struct.hpp"
#include "Data/Struct_fac.hpp"

#include <algorithm>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &operator<<(std::ostream &os, const Struct *c) {
  os << "*";
  c->to_stream(os);
  return os;
}

std::pair<std::string, char> get_word(std::istream &is,
                                      std::vector<char> one_of) {
  std::stringstream ss;
  char l_c;
  while (true) {
    l_c = is.peek();
    if (std::find(one_of.begin(), one_of.end(), l_c) != one_of.end()) {
      break;
    }
    ss << (char)is.get();
  }

  return std::make_pair(ss.str(), l_c);
}

std::string get_type(std::istream &is) {
  std::string type;
  int tg = is.tellg();
  is.ignore(100, ':');
  auto d = get_word(is, {'}', ','});
  is.seekg(tg);
  return d.first;
}

std::istream &operator>>(std::istream &is, Struct *&c) {

  if (c != NULL) {
    delete c;
  }

  if (is.peek() == '0') {
    c = NULL;
    return is;
  }

  char cc = is.peek();
  if (cc == 'N' || cc == 'N') {
    std::string need_null;
    is >> need_null;
    if (need_null == "NULL" || need_null == "Null" || need_null == "null") {
      c = NULL;
      return is;
    }
    throw "error in NULL word";
  }

  if (is.peek() != '*') {
    throw "Not Pointer";
  }

  // remove the *
  is.get();
  std::string t = get_type(is);
  c = Struct_fac::get_inst().build(t, is);
  return is;
}