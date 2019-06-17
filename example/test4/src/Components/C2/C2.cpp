
#include "Components/C2/C2.hpp"
#include <iostream>

namespace C2 {

C2::C2()
    : /* PROVIDE */
      b(this),
      /* REQUIRE */
      a(NULL) {
  std::cout << "--CONST : C2" << std::endl;
  return;
}

//! Destructor
C2::~C2() noexcept {
  std::cout << "--DEST  : C2" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void C2::configuration() {
  Component::configuration();
  std::cout << "--CONF  : C2" << std::endl;
  return;
}

void C2::connection() {
  Component::connection();
  std::cout << "--CONECT: C2" << std::endl;
  return;
}

void C2::start() {
  Component::start();
  std::cout << "--START : C2" << std::endl;
  return;
}

void C2::step() {
  Component::step();
  std::cout << "--STEP  : C2" << std::endl;
  return;
}

void C2::stop() {
  std::cout << "--STOP  : C2" << std::endl;
  return;
}

void C2::status() {
  Component::status();
  std::cout << "--STATUS: C2" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

Ia_b &C2::get_b() { return this->b; }

// REQUIRE //////////////////////////////////////////////////////////////////

Ia *&C2::get_a() { return this->a; }

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

} // namespace C2