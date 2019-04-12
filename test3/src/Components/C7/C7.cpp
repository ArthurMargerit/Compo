
#include <iostream>

#include "Components/C7/C7.hpp"

namespace C7 {

C7::C7() {
  std::cout << "--CONST : C7" << std::endl;
  return;
}

//! Destructor
C7::~C7() noexcept {
  std::cout << "--DEST  : C7" << std::endl;
  return;
}

void C7::configuration() {
  std::cout << "--CONF  : C7" << std::endl;
  return;
}

void C7::connection() {
  std::cout << "--CONECT: C7" << std::endl;
  return;
}

void C7::start() {
  std::cout << "--START : C7" << std::endl;
  return;
}

void C7::step() {
  std::cout << "--STEP  : C7" << std::endl;
  return;
}

void C7::stop() {
  std::cout << "--STOP  : C7" << std::endl;
  return;
}

void C7::status() {
  std::cout << "--STATUS: C7" << std::endl;
  return;
}
}