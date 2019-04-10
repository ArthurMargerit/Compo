
#include <iostream>

#include "Components/Empty_logger_c/Empty_logger_c.hpp"

namespace Empty_logger_c {

Empty_logger_c::Empty_logger_c()
    : /* PROVIDE */
      log(this) {
  std::cout << "--CONST : Empty_logger_c" << std::endl;
  return;
}

//! Destructor
Empty_logger_c::~Empty_logger_c() noexcept {
  std::cout << "--DEST  : Empty_logger_c" << std::endl;
  return;
}

void Empty_logger_c::configuration() {
  std::cout << "--CONF  : Empty_logger_c" << std::endl;
  return;
}

void Empty_logger_c::connection() {
  std::cout << "--CONECT: Empty_logger_c" << std::endl;
  return;
}

void Empty_logger_c::start() {
  std::cout << "--START : Empty_logger_c" << std::endl;
  return;
}

void Empty_logger_c::step() {
  std::cout << "--STEP  : Empty_logger_c" << std::endl;
  return;
}

void Empty_logger_c::stop() {
  std::cout << "--STOP  : Empty_logger_c" << std::endl;
  return;
}

void Empty_logger_c::status() {
  std::cout << "--STATUS: Empty_logger_c" << std::endl;
  return;
}

} // namespace Empty_logger_c