
#include <iostream>

#include "Components/C4/C4.hpp"

namespace C4 {

C4::C4()
    : /* REQUIRE */
      a(NULL),
      /* DATA */
      d(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : C4" << std::endl;
  return;
}

//! Destructor
C4::~C4() noexcept {
  std::cout << "--DEST  : C4" << std::endl;
  return;
}

void C4::configuration() {
  std::cout << "--CONF  : C4" << std::endl;
  return;
}

void C4::connection() {
  std::cout << "--CONECT: C4" << std::endl;
  return;
}

void C4::start() {
  std::cout << "--START : C4" << std::endl;
  return;
}

void C4::step() {
  std::cout << "--STEP  : C4" << std::endl;
  return;
}

void C4::stop() {
  std::cout << "--STOP  : C4" << std::endl;
  return;
}

void C4::status() {
  std::cout << "--STATUS: C4" << std::endl;
  return;
}
}