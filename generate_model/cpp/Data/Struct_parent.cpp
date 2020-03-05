
#include "Data/Struct.hpp"
#include "Data/Struct_fac.hpp"

#include <algorithm>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

Struct::~Struct(){}

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

void p_from_stream(std::istream& is, Struct *& p_c, Serialization_context& p_ctx) {
  if(is.peek() != '*') {
    std::cerr << "stream is not a pointer";
    throw "stream is not a pointer";
  }
  is.get();

  if(is.peek() != '('){
    std::cerr << "is not a right addr declaration start";
    throw "is not a right addr declaration start";
  }
  is.get();

  void * addr;
  is >> addr;
  p_ctx.get_loc(addr, p_c);

  if(is.peek() != ')') {
    std::cerr << "is not a right addr declaration end";
    throw "is not a right addr declaration end";
  }
  is.get();
}

void p_to_stream(std::ostream &os, const Struct *c, Serialization_context& p_ctx) {
  os << "*(" << (void*) c << ")";
  p_ctx.want(c);
}

std::ostream &operator<<(std::ostream &os, const Struct *c) {
  Serialization_context l_ctx;
  p_to_stream(os, c, l_ctx);
  l_ctx.export_wanted(os);
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

// std::istream &operator>>(std::istream &is, Struct *&c) {

//   // if (c != NULL) {
//   //   delete c;
//   // }

//   // if (is.peek() == '0') {
//   //   c = NULL;
//   //   return is;
//   // }

//   // char cc = is.peek();
//   // if (cc == 'N' || cc == 'n') {
//   //   std::string need_null;
//   //   is >> need_null;
//   //   if (need_null == "NULL" || need_null == "Null" || need_null == "null") {
//   //     c = NULL;
//   //     return is;
//   //   }
//   //   throw "error in NULL word";
//   // }

//   // if (is.peek() != '*') {
//   //   throw "Not Pointer";
//   // }

//   // // remove the *
//   // is.get();
//   // std::string t = get_type(is);
//   // c = Struct_fac::get_inst().build(t, is);
//   return is;
// }
