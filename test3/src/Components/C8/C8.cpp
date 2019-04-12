
#include <iostream>

#include "Components/C8/C8.hpp"

namespace C8 {

C8::C8() {
  std::cout << "--CONST : C8" << std::endl;
  return;
}

//! Destructor
C8::~C8() noexcept {
  std::cout << "--DEST  : C8" << std::endl;
  return;
}

void C8::configuration() {
  std::cout << "--CONF  : C8" << std::endl;
  return;
}

void C8::connection() {
  std::cout << "--CONECT: C8" << std::endl;
  return;
}

void C8::start() {
  std::cout << "--START : C8" << std::endl;
  return;
}

void C8::step() {
  std::cout << "--STEP  : C8" << std::endl;
  return;
}

void C8::stop() {
  std::cout << "--STOP  : C8" << std::endl;
  return;
}

void C8::status() {
  std::cout << "--STATUS: C8" << std::endl;
  return;
}
}