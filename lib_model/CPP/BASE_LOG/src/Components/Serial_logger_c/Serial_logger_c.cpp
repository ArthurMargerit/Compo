
#include <iostream>

#include "Components/Serial_logger_c/Serial_logger_c.hpp"

namespace Serial_logger_c {

Serial_logger_c::Serial_logger_c()
    : /* PROVIDE */
      log(this),
      /* DATA */
      color(false), format(simple) {
  std::cout << "--CONST : Serial_logger_c" << std::endl;
  return;
}

//! Destructor
Serial_logger_c::~Serial_logger_c() noexcept {
  std::cout << "--DEST  : Serial_logger_c" << std::endl;
  return;
}

void Serial_logger_c::configuration() {
  std::cout << "--CONF  : Serial_logger_c" << std::endl;
  return;
}

void Serial_logger_c::connection() {
  std::cout << "--CONECT: Serial_logger_c" << std::endl;
  return;
}

void Serial_logger_c::start() {
  std::cout << "--START : Serial_logger_c" << std::endl;
  return;
}

void Serial_logger_c::step() {
  std::cout << "--STEP  : Serial_logger_c" << std::endl;
  return;
}

void Serial_logger_c::stop() {
  std::cout << "--STOP  : Serial_logger_c" << std::endl;
  return;
}

void Serial_logger_c::status() {
  std::cout << "--STATUS: Serial_logger_c" << std::endl;
  return;
}
}