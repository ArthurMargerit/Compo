#include "Errors/Error.hpp"
#include "Serialization_context.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include <sstream>

namespace CompoMe {

Error::Error() {}
Error::~Error() {}

std::string Error::what_s() const { return std::string("-> Error\n"); }

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
  p_from_stream(is, (Error *&)c, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

std::istream &operator>>(std::istream &is, std::shared_ptr<Error> &c) {
  assert(1);
  return is;
}

} // namespace CompoMe
