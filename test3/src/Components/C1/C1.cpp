
#include <iostream>

#include "Components/C1/C1.hpp"

namespace C1 {

C1::C1()
    : /* PROVIDE */
      a(this),
      b(this), g(this),
      /* REQUIRE */
      c(NULL), d(NULL) {
  std::cout << "--CONST : C1" << std::endl;
  return;
}

//! Destructor
C1::~C1() noexcept {
  std::cout << "--DEST  : C1" << std::endl;
  return;
}

void C1::configuration() {
  std::cout << "--CONF  : C1" << std::endl;
  return;
}

void C1::connection() {
  std::cout << "--CONECT: C1" << std::endl;
  return;
}

void C1::start() {
  std::cout << "--START : C1" << std::endl;
  return;
}

void C1::step() {
  std::cout << "--STEP  : C1" << std::endl;
  return;
}

void C1::stop() {
  std::cout << "--STOP  : C1" << std::endl;
  return;
}

void C1::status() {
  std::cout << "--STATUS: C1" << std::endl;
  return;
}
}