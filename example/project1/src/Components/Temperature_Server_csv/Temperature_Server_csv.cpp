
#include <iostream>

#include "Components/Temperature_Server_csv/Temperature_Server_csv.hpp"

namespace Temperature_Server_csv {

Temperature_Server_csv::Temperature_Server_csv()
    : /* DATA */
      save_path("UNDEF") {
  std::cout << "--CONST : Temperature_Server_csv" << std::endl;
  return;
}

//! Destructor
Temperature_Server_csv::~Temperature_Server_csv() noexcept {
  std::cout << "--DEST  : Temperature_Server_csv" << std::endl;
  return;
}

void Temperature_Server_csv::configuration() {
  std::cout << "--CONF  : Temperature_Server_csv" << std::endl;
  return;
}

void Temperature_Server_csv::connection() {
  std::cout << "--CONECT: Temperature_Server_csv" << std::endl;
  return;
}

void Temperature_Server_csv::start() {
  std::cout << "--START : Temperature_Server_csv" << std::endl;
  return;
}

void Temperature_Server_csv::step() {
  std::cout << "--STEP  : Temperature_Server_csv" << std::endl;
  return;
}

void Temperature_Server_csv::stop() {
  std::cout << "--STOP  : Temperature_Server_csv" << std::endl;
  return;
}

void Temperature_Server_csv::status() {
  std::cout << "--STATUS: Temperature_Server_csv" << std::endl;
  return;
}
}