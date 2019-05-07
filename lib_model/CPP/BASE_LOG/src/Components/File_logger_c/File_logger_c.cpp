
#include <iostream>

#include "Components/File_logger_c/File_logger_c.hpp"

namespace File_logger_c {

File_logger_c::File_logger_c()
    : /* PROVIDE */
      log(this),
      /* DATA */
      file_path("UNDEF"), format(simple) {
  std::cout << "--CONST : File_logger_c" << std::endl;
  return;
}

//! Destructor
File_logger_c::~File_logger_c() noexcept {
  std::cout << "--DEST  : File_logger_c" << std::endl;
  return;
}

void File_logger_c::configuration() {
  std::cout << "--CONF  : File_logger_c" << std::endl;
  return;
}

void File_logger_c::connection() {
  std::cout << "--CONECT: File_logger_c" << std::endl;
  return;
}

void File_logger_c::start() {
  std::cout << "--START : File_logger_c" << std::endl;
  return;
}

void File_logger_c::step() {
  std::cout << "--STEP  : File_logger_c" << std::endl;
  return;
}

void File_logger_c::stop() {
  std::cout << "--STOP  : File_logger_c" << std::endl;
  return;
}

void File_logger_c::status() {
  std::cout << "--STATUS: File_logger_c" << std::endl;
  return;
}
}