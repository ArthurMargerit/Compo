#include "Errors/Error.hpp"
#include "Errors/Error_fac.hpp"
#include <ostream>

std::string Error::what() {
  return std::string("-> Error\n");
}

std::ostream &operator<<(std::ostream &os, const Error &e) {
  e.to_stream(os);
  return os;
}

std::istream &operator>>(std::istream &is, Error *&c) {
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

  if (is.peek() != '!') {
    throw "Not Error";
  }

  // remove the !
  is.get();
  std::string t = get_type(is);
  c = Error_fac::get_inst().build(t, is);

  return is;
}
