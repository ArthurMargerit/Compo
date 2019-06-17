
#include "Components/C_t2r/C_t2r.hpp"
#include <iostream>

namespace C_t2r {

C_t2r::C_t2r()
    : /* DATA */
      c(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : C_t2r" << std::endl;
  return;
}

//! Destructor
C_t2r::~C_t2r() noexcept {
  std::cout << "--DEST  : C_t2r" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_t2r::configuration() {
  C_t1r::configuration();
  std::cout << "--CONF  : C_t2r" << std::endl;
  return;
}

void C_t2r::connection() {
  C_t1r::connection();
  std::cout << "--CONECT: C_t2r" << std::endl;
  return;
}

void C_t2r::start() {
  C_t1r::start();
  std::cout << "--START : C_t2r" << std::endl;
  return;
}

void C_t2r::step() {
  C_t1r::step();
  std::cout << "--STEP  : C_t2r" << std::endl;
  return;
}

void C_t2r::stop() {
  std::cout << "--STOP  : C_t2r" << std::endl;
  return;
}

void C_t2r::status() {
  C_t1r::status();
  std::cout << "--STATUS: C_t2r" << std::endl;
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

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// c
A C_t2r::get_c() const { return this->c; }

void C_t2r::set_c(const A c) { this->c = c; }
}