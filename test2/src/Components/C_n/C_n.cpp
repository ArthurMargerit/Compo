
#include "Components/C_n/C_n.hpp"
#include <iostream>

namespace C_n {

C_n::C_n()
    : /* PROVIDE */
      i_p1(this),
      i_p2(this),
      /* REQUIRE */
      i_r(NULL), i_r1(NULL), i_r2(NULL) {
  std::cout << "--CONST : C_n" << std::endl;
  return;
}

//! Destructor
C_n::~C_n() noexcept {
  std::cout << "--DEST  : C_n" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_n::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C_n" << std::endl;
  return;
}

void C_n::connection() {
  Component::connection();
  std::cout << "--CONECT: C_n" << std::endl;
  return;
}

void C_n::start() {
  Component::start();
  std::cout << "--START : C_n" << std::endl;
  return;
}

void C_n::step() {
  Component::step();
  std::cout << "--STEP  : C_n" << std::endl;
  return;
}

void C_n::stop() {
  std::cout << "--STOP  : C_n" << std::endl;
  return;
}

void C_n::status() {
  Component::status();
  std::cout << "--STATUS: C_n" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

I_t3_i_p1 &C_n::get_i_p1() { return this->i_p1; }

I_t4_i_p2 &C_n::get_i_p2() { return this->i_p2; }

// REQUIRE //////////////////////////////////////////////////////////////////

I_t2 *&C_n::get_i_r() { return this->i_r; }

I_t3 *&C_n::get_i_r1() { return this->i_r1; }

I_t4 *&C_n::get_i_r2() { return this->i_r2; }

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////
}