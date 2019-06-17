
#include <iostream>

#include "Components/C3/C3.hpp"

namespace C3 {

C3::C3()
    : /* REQUIRE */
      c(NULL),
      d(NULL) {
  std::cout << "--CONST : C3" << std::endl;
  return;
}

//! Destructor
C3::~C3() noexcept {
  std::cout << "--DEST  : C3" << std::endl;
  return;
}

void C3::configuration() {
  std::cout << "--CONF  : C3" << std::endl;
  return;
}

void C3::connection() {
  std::cout << "--CONECT: C3" << std::endl;
  return;
}

void C3::start() {
  std::cout << "--START : C3" << std::endl;
  return;
}

void C3::step() {
  std::cout << "--STEP  : C3" << std::endl;
  return;
}

void C3::stop() {
  std::cout << "--STOP  : C3" << std::endl;
  return;
}

void C3::status() {
  std::cout << "--STATUS: C3" << std::endl;
  return;
}
}