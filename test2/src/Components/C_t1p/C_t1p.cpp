
#include "Components/C_t1p/C_t1p.hpp"
#include <iostream>

namespace C_t1p {

C_t1p::C_t1p()
    : /* PROVIDE */
      i_p(this),
      i_p2(this),
      /* DATA */
      a(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : C_t1p" << std::endl;
  return;
}

//! Destructor
C_t1p::~C_t1p() noexcept {
  std::cout << "--DEST  : C_t1p" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_t1p::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C_t1p" << std::endl;
  return;
}

void C_t1p::connection() {
  Component::connection();
  std::cout << "--CONECT: C_t1p" << std::endl;
  return;
}

void C_t1p::start() {
  Component::start();
  std::cout << "--START : C_t1p" << std::endl;
  return;
}

void C_t1p::step() {
  Component::step();
  std::cout << "--STEP  : C_t1p" << std::endl;
  return;
}

void C_t1p::stop() {
  std::cout << "--STOP  : C_t1p" << std::endl;
  return;
}

void C_t1p::status() {
  Component::status();
  std::cout << "--STATUS: C_t1p" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

I_t2_i_p &C_t1p::get_i_p() { return this->i_p; }

I_t1_i_p2 &C_t1p::get_i_p2() { return this->i_p2; }

// REQUIRE //////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// a
A C_t1p::get_a() const { return this->a; }

void C_t1p::set_a(const A a) { this->a = a; }
}