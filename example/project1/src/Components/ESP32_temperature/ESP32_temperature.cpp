
#include <iostream>

#include "Components/ESP32_temperature/ESP32_temperature.hpp"

namespace ESP32_temperature {

ESP32_temperature::ESP32_temperature()
    : /* PROVIDE */
      room_temp(this),
      /* REQUIRE */
      out(NULL),
      /* DATA */
      freq(0), room("UNDEF") {
  std::cout << "--CONST : ESP32_temperature" << std::endl;
  return;
}

//! Destructor
ESP32_temperature::~ESP32_temperature() noexcept {
  std::cout << "--DEST  : ESP32_temperature" << std::endl;
  return;
}

void ESP32_temperature::configuration() {
  std::cout << "--CONF  : ESP32_temperature" << std::endl;
  return;
}

void ESP32_temperature::connection() {
  std::cout << "--CONECT: ESP32_temperature" << std::endl;
  return;
}

void ESP32_temperature::start() {
  std::cout << "--START : ESP32_temperature" << std::endl;
  return;
}

void ESP32_temperature::step() {
  std::cout << "--STEP  : ESP32_temperature" << std::endl;
  return;
}

void ESP32_temperature::stop() {
  std::cout << "--STOP  : ESP32_temperature" << std::endl;
  return;
}

void ESP32_temperature::status() {
  std::cout << "--STATUS: ESP32_temperature" << std::endl;
  return;
}
}