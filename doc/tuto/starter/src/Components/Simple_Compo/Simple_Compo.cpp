
#include <iostream>

#include "Components/Simple_Compo/Simple_Compo.hpp"

namespace Simple_Compo {

Simple_Compo::Simple_Compo()
    : /* PROVIDE */
      interface(this) {
  std::cout << "--CONST : Simple_Compo" << std::endl;
  return;
}

//! Destructor
Simple_Compo::~Simple_Compo() noexcept {
  std::cout << "--DEST  : Simple_Compo" << std::endl;
  return;
}

void Simple_Compo::configuration() {
  std::cout << "--CONF  : Simple_Compo" << std::endl;
  return;
}

void Simple_Compo::connection() {
  std::cout << "--CONECT: Simple_Compo" << std::endl;
  return;
}

void Simple_Compo::start() {
  std::cout << "--START : Simple_Compo" << std::endl;
  return;
}

void Simple_Compo::step() {
  std::cout << "--STEP  : Simple_Compo" << std::endl;
  return;
}

void Simple_Compo::stop() {
  std::cout << "--STOP  : Simple_Compo" << std::endl;
  return;
}

void Simple_Compo::status() {
  std::cout << "--STATUS: Simple_Compo" << std::endl;
  return;
}

} // namespace Simple_Compo