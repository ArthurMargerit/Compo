#include "Errors/Error.hpp"
#include "Errors/Error_fac.hpp"
#include <ostream>
#include <sstream>

Error::~Error(){}

std::string Error::what()  {
  return std::string("-> Error\n");
}

std::ostream &operator<<(std::ostream &os, const Error *e) {
  if(e == nullptr) {
    os << "0";
    return os;
  }

  os << "*";
  e->to_stream(os);
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Error>& e) {
  if(e == nullptr) {
    os << "0";
    return os;
  }

  os << "*";
  e->to_stream(os);
  return os;
}

std::istream &operator>>(std::istream &is, std::shared_ptr<Error> &c){

  if (is.peek() == '0') {
    is.get();
    c = std::shared_ptr<Error>();
    return is;
  }

  char cc = is.peek();
  if (cc == 'N') {
    std::string need_null;
    is >> need_null;
    if (need_null == "NULL" || need_null == "Null" || need_null == "null") {
      c =  std::shared_ptr<Error>();
      return is;
    }
    throw "error in NULL word";
  }

  if (is.peek() != '*') {
    throw ("Not compliant with Error* ");
  }

  // remove the *
  is.get();
  std::string t = "TODO";//get_type(is);
  c = Error_fac::get_inst().build_sp(t, is);
  return is;
}

std::istream &operator>>(std::istream &is, Error *&c) {
  if (c != NULL) {
    delete c;
  }

  if (is.peek() == '0') {
    is.get();
    c = NULL;
    return is;
  }

  char cc = is.peek();
  if (cc == 'N') {
    std::string need_null;
    is >> need_null;
    if (need_null == "NULL" || need_null == "Null" || need_null == "null") {
      c = NULL;
      return is;
    }
    throw "error in NULL word";
  }

  if (is.peek() != '*') {
    throw ("Not compliant with Error* ");
  }

  // remove the *
  is.get();
  std::string t ="TODO";// get_type(is);
  c = Error_fac::get_inst().build(t, is);
  return is;
}
