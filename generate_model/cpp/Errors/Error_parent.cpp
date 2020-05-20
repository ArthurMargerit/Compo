#include "Errors/Error.hpp"
#include "Serialization_context.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include <sstream>

Error::Error() {}
Error::~Error() {}

std::string Error::what() { return std::string("-> Error\n"); }

// std::istream &operator>>(std::istream &is, std::shared_ptr<Error> &c){

//   if (is.peek() == '0') {
//     is.get();
//     c = std::shared_ptr<Error>();
//     return is;
//   }

//   char cc = is.peek();
//   if (cc == 'N') {
//     std::string need_null;
//     is >> need_null;
//     if (need_null == "NULL" || need_null == "Null" || need_null == "null") {
//       c =  std::shared_ptr<Error>();
//       return is;
//     }
//     throw "error in NULL word";
//   }

//   if (is.peek() != '*') {
//     throw ("Not compliant with Error* ");
//   }

//   // remove the *
//   is.get();
//   std::string t = get_type(is);
//   c = Error_fac::get_inst().build_sp(t, is);
//   return is;
// }

// std::istream &operator>>(std::istream &is, Error *&c) {
//   if (c != NULL) {
//     delete c;
//   }

//   if (is.peek() == '0') {
//     is.get();
//     c = NULL;
//     return is;
//   }

//   char cc = is.peek();
//   if (cc == 'N') {
//     std::string need_null;
//     is >> need_null;
//     if (need_null == "NULL" || need_null == "Null" || need_null == "null") {
//       c = NULL;
//       return is;
//     }
//     throw "error in NULL word";
//   }

//   if (is.peek() != '*') {
//     throw ("Not compliant with Error* ");
//   }

//   // remove the *
//   is.get();
//   std::string t = get_type(is);
//   c = Error_fac::get_inst().build(t, is);
//   return is;
// }

void p_from_stream(std::istream &is, Error *&p_c,
                   Serialization_context_import &p_ctx) {
  if (is.peek() != '*') {
    std::cerr << "stream is not a pointer";
    throw "stream is not a pointer";
  }
  is.get();

  if (is.peek() != '(') {
    std::cerr << "is not a right addr declaration start";
    throw "is not a right addr declaration start";
  }
  is.get();

  void *addr;
  is >> addr;
  // p_ctx.get_loc(addr, p_c);

  if (is.peek() != ')') {
    std::cerr << "is not a right addr declaration end";
    throw "is not a right addr declaration end";
  }
  is.get();
}

void p_from_stream(std::istream &is, std::shared_ptr<Error> &p_c,
                   Serialization_context_import &p_ctx) {
  if (is.peek() != '*') {
    std::cerr << "stream is not a pointer";
    throw "stream is not a pointer";
  }
  is.get();

  if (is.peek() != '(') {
    std::cerr << "is not a right addr declaration start";
    throw "is not a right addr declaration start";
  }
  is.get();

  void *addr;
  is >> addr;
  // p_ctx.get_loc(addr, p_c);

  if (is.peek() != ')') {
    std::cerr << "is not a right addr declaration end";
    throw "is not a right addr declaration end";
  }
  is.get();
}

void p_to_stream(std::ostream &os, const Error *c,
                 Serialization_context_export &p_ctx) {
  os << "*(" << (void *)c << ")";
  p_ctx.want(c);
}

void p_to_stream(std::ostream &os, const std::shared_ptr<Error> c,
                 Serialization_context_export &p_ctx) {
  p_to_stream(os, c.get(), p_ctx);
}

// std::pair<std::string, char> get_word(std::istream &is,
//                                       std::vector<char> one_of) {
//   std::stringstream ss;
//   char l_c;
//   while (true) {
//     l_c = is.peek();
//     if (std::find(one_of.begin(), one_of.end(), l_c) != one_of.end()) {
//       break;
//     }
//     ss << (char)is.get();
//   }

//   return std::make_pair(ss.str(), l_c);
// }

std::ostream &operator<<(std::ostream &os, const Error *c) {
  Serialization_context_export l_ctx;
  p_to_stream(os, c, l_ctx);
  l_ctx.export_wanted(os);
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Error> &c) {
  Serialization_context_export l_ctx;
  p_to_stream(os, c, l_ctx);
  l_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, Error *&c) {
  Serialization_context_import p_ctx;
  p_from_stream(is, (Error *&) c, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

std::istream &operator>>(std::istream &is, std::shared_ptr<Error> &c) {
  assert(1);
  // std::cout << "lapin is coming" <<std::endl;// "\n";
  // Serialization_context p_ctx;
  // p_from_stream(is, (Struct*&) c, p_ctx);
  // p_ctx.import_wanted(is);
  return is;
}
