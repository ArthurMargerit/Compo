#include "Interfaces/I_t1/I_t1_fake.hpp"

I_t1_fake::I_t1_fake(Function_stream &out, Return_stream &in) : Fake(out, in) {}

I_t1_fake::~I_t1_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function I_t1 ////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set I_t1 /////////////////////////////////////////////////
A I_t1_fake::get_sa() const {
  o.start();
  o << "get_sa()";
  o.call();

  i.pull();
  A ret;
  i >> ret;
  i.end();

  return ret;
}

void I_t1_fake::set_sa(const A sa) {

  o << "set_sa(" << sa << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}
B I_t1_fake::get_sb() const {
  o.start();
  o << "get_sb()";
  o.call();

  i.pull();
  B ret;
  i >> ret;
  i.end();

  return ret;
}

void I_t1_fake::set_sb(const B sb) {

  o << "set_sb(" << sb << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}
C I_t1_fake::get_sc() const {
  o.start();
  o << "get_sc()";
  o.call();

  i.pull();
  C ret;
  i >> ret;
  i.end();

  return ret;
}

void I_t1_fake::set_sc(const C sc) {

  o << "set_sc(" << sc << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}
D I_t1_fake::get_sd() const {
  o.start();
  o << "get_sd()";
  o.call();

  i.pull();
  D ret;
  i >> ret;
  i.end();

  return ret;
}

void I_t1_fake::set_sd(const D sd) {

  o << "set_sd(" << sd << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}