
#include <iostream>

#include "Components/Computer_temperature/Computer_temperature.hpp"

namespace Computer_temperature {

Computer_temperature::Computer_temperature()
    : /* PROVIDE */
      cpu_temp(this),
      gpu_temp(this),
      /* REQUIRE */
      report(NULL),
      /* DATA */
      freq(0) {
  std::cout << "--CONST : Computer_temperature" << std::endl;
  return;
}

//! Destructor
Computer_temperature::~Computer_temperature() noexcept {
  std::cout << "--DEST  : Computer_temperature" << std::endl;
  return;
}

void Computer_temperature::configuration() {
  std::cout << "--CONF  : Computer_temperature" << std::endl;
  return;
}

void Computer_temperature::connection() {
  std::cout << "--CONECT: Computer_temperature" << std::endl;
  return;
}

void Computer_temperature::start() {
  std::cout << "--START : Computer_temperature" << std::endl;
  return;
}

void Computer_temperature::step() {
  std::cout << "--STEP  : Computer_temperature" << std::endl;
  return;
}

void Computer_temperature::stop() {
  std::cout << "--STOP  : Computer_temperature" << std::endl;
  return;
}

void Computer_temperature::status() {
  std::cout << "--STATUS: Computer_temperature" << std::endl;
  return;
}
}