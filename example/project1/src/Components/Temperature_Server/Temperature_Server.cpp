
#include <iostream>

#include "Components/Temperature_Server/Temperature_Server.hpp"

namespace Temperature_Server {

Temperature_Server::Temperature_Server()
    : /* PROVIDE */
      reporter(this) {
  std::cout << "--CONST : Temperature_Server" << std::endl;
  return;
}

//! Destructor
Temperature_Server::~Temperature_Server() noexcept {
  std::cout << "--DEST  : Temperature_Server" << std::endl;
  return;
}

void Temperature_Server::configuration() {
  std::cout << "--CONF  : Temperature_Server" << std::endl;
  return;
}

void Temperature_Server::connection() {
  std::cout << "--CONECT: Temperature_Server" << std::endl;
  return;
}

void Temperature_Server::start() {
  std::cout << "--START : Temperature_Server" << std::endl;
  return;
}

void Temperature_Server::step() {
  std::cout << "--STEP  : Temperature_Server" << std::endl;
  return;
}

void Temperature_Server::stop() {
  std::cout << "--STOP  : Temperature_Server" << std::endl;
  return;
}

void Temperature_Server::status() {
  std::cout << "--STATUS: Temperature_Server" << std::endl;
  return;
}

int Temperature_Server::save() { return 0; }

int Temperature_Server::display() { return 0; }

void Temperature_Server::add(Temperature_sample ts) { return; }
}