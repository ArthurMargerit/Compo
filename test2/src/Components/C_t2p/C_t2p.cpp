
#include "Components/C_t2p/C_t2p.hpp"
#include <iostream>

namespace C_t2p {

C_t2p::C_t2p()
    : /* DATA */
      d(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : C_t2p" << std::endl;
  return;
}

//! Destructor
C_t2p::~C_t2p() noexcept {
  std::cout << "--DEST  : C_t2p" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C_t2p::configuration() {
  C_t1p::configuration();
  std::cout << "--CONF  : C_t2p" << std::endl;
  return;
}

void C_t2p::connection() {
  C_t1p::connection();
  std::cout << "--CONECT: C_t2p" << std::endl;
  return;
}

void C_t2p::start() {
  C_t1p::start();
  std::cout << "--START : C_t2p" << std::endl;
  return;
}

void C_t2p::step() {
  C_t1p::step();
  std::cout << "--STEP  : C_t2p" << std::endl;
  return;
}

void C_t2p::stop() {
  std::cout << "--STOP  : C_t2p" << std::endl;
  return;
}

void C_t2p::status() {
  C_t1p::status();
  std::cout << "--STATUS: C_t2p" << std::endl;
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

// d
A C_t2p::get_d() const { return this->d; }

void C_t2p::set_d(const A d) { this->d = d; }
}