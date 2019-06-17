
#include <iostream>

#include "Components/C2/C2.hpp"

namespace C2 {

C2::C2()
    : /* PROVIDE */
      a(this),
      b(this) {
  std::cout << "--CONST : C2" << std::endl;
  return;
}

//! Destructor
C2::~C2() noexcept {
  std::cout << "--DEST  : C2" << std::endl;
  return;
}

void C2::configuration() {
  std::cout << "--CONF  : C2" << std::endl;
  return;
}

void C2::connection() {
  std::cout << "--CONECT: C2" << std::endl;
  return;
}

void C2::start() {
  std::cout << "--START : C2" << std::endl;
  return;
}

void C2::step() {
  std::cout << "--STEP  : C2" << std::endl;
  return;
}

void C2::stop() {
  std::cout << "--STOP  : C2" << std::endl;
  return;
}

void C2::status() {
  std::cout << "--STATUS: C2" << std::endl;
  return;
}
}