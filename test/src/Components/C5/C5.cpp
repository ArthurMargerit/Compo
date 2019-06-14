
#include <iostream>

#include "Components/C5/C5.hpp"

namespace C5 {

C5::C5()
    : /* PROVIDE */
      a(this),
      /* DATA */
      p(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : C5" << std::endl;
  return;
}

//! Destructor
C5::~C5() noexcept {
  std::cout << "--DEST  : C5" << std::endl;
  return;
}

void C5::configuration() {
  std::cout << "--CONF  : C5" << std::endl;
  return;
}

void C5::connection() {
  std::cout << "--CONECT: C5" << std::endl;
  return;
}

void C5::start() {
  std::cout << "--START : C5" << std::endl;
  return;
}

void C5::step() {
  std::cout << "--STEP  : C5" << std::endl;
  return;
}

void C5::stop() {
  std::cout << "--STOP  : C5" << std::endl;
  return;
}

void C5::status() {
  std::cout << "--STATUS: C5" << std::endl;
  return;
}

int C5::f1() { return 0; }

int C5::f2(int a) { return 0; }

int C5::f3(int a, int b) { return 0; }
}