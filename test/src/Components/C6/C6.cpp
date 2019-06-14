
#include <iostream>

#include "Components/C6/C6.hpp"

namespace C6 {

C6::C6()
    : /* PROVIDE */
      a(this),
      /* REQUIRE */
      b(NULL),
      /* DATA */
      v1(9), v2(0), v3(-1) {
  std::cout << "--CONST : C6" << std::endl;
  return;
}

//! Destructor
C6::~C6() noexcept {
  std::cout << "--DEST  : C6" << std::endl;
  return;
}

void C6::configuration() {
  std::cout << "--CONF  : C6" << std::endl;
  return;
}

void C6::connection() {
  std::cout << "--CONECT: C6" << std::endl;
  return;
}

void C6::start() {
  std::cout << "--START : C6" << std::endl;
  return;
}

void C6::step() {
  std::cout << "--STEP  : C6" << std::endl;
  return;
}

void C6::stop() {
  std::cout << "--STOP  : C6" << std::endl;
  return;
}

void C6::status() {
  std::cout << "--STATUS: C6" << std::endl;
  return;
}
}