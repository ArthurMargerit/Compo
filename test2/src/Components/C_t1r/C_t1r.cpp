
#include "Components/C_t1r/C_t1r.hpp"
#include <iostream>

namespace C_t1r {

C_t1r::C_t1r()
    : /* REQUIRE */
      i_r(NULL),
      /* DATA */
      b(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : C_t1r" << std::endl;
  return;
}

//! Destructor
C_t1r::~C_t1r() noexcept {
  std::cout << "--DEST  : C_t1r" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_t1r::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C_t1r" << std::endl;
  return;
}

void C_t1r::connection() {
  Component::connection();
  std::cout << "--CONECT: C_t1r" << std::endl;
  return;
}

void C_t1r::start() {
  Component::start();
  std::cout << "--START : C_t1r" << std::endl;
  return;
}

void C_t1r::step() {
  Component::step();
  std::cout << "--STEP  : C_t1r" << std::endl;
  return;
}

void C_t1r::stop() {
  std::cout << "--STOP  : C_t1r" << std::endl;
  return;
}

void C_t1r::status() {
  Component::status();
  std::cout << "--STATUS: C_t1r" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

// REQUIRE //////////////////////////////////////////////////////////////////

I_t1 *&C_t1r::get_i_r() { return this->i_r; }

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// b
A C_t1r::get_b() const { return this->b; }

void C_t1r::set_b(const A b) { this->b = b; }
}