#include "Interfaces/Ia/Ia_fake.hpp"

Ia_fake::Ia_fake(Function_stream &out, Return_stream &in) : Fake(out, in) {}

Ia_fake::~Ia_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Ia ////////////////////////////////////////////////

int_tt Ia_fake::ping(vec<int_tt> p) {
  o.start();
  o << "ping("

    << p

    << ")";
  o.call();

  i.pull();

  int_tt ri;
  i >> ri;
  i.end();
  return ri;
}

int_tt Ia_fake::pp(vec<int_tt> p1, vec<d> p2) {
  o.start();
  o << "pp("

    << p1 << ","

    << p2

    << ")";
  o.call();

  i.pull();

  int_tt ri;
  i >> ri;
  i.end();
  return ri;
}

vec<int_tt> Ia_fake::p() {
  o.start();
  o << "p("

    << ")";
  o.call();

  i.pull();

  vec<int_tt> ri;
  i >> ri;
  i.end();
  return ri;
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Ia /////////////////////////////////////////////////
vec<int_tt> Ia_fake::get_v1() const {
  o.start();
  o << "get_v1()";
  o.call();

  i.pull();
  vec<int_tt> ret;
  i >> ret;
  i.end();

  return ret;
}

void Ia_fake::set_v1(const vec<int_tt> v1) {

  o << "set_v1(" << v1 << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}
vec<d> Ia_fake::get_v2() const {
  o.start();
  o << "get_v2()";
  o.call();

  i.pull();
  vec<d> ret;
  i >> ret;
  i.end();

  return ret;
}

void Ia_fake::set_v2(const vec<d> v2) {

  o << "set_v2(" << v2 << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}