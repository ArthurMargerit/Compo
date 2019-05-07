#include "Links/Direct/Direct.hpp"

#include <iostream>

Direct::Direct():from(NULL),to(NULL),connected(false) {}

Direct::~Direct() {}

void Direct::set_from_to(Interface **pfrom, Interface *pto) {
  this->from = pfrom;
  this->to = pto;
}

void Direct::step() {}

void Direct::connect() {
  if (this->from) {
    *(this->from) = this->to;
    this->connected = true;
  } else {
    std::cerr << "connection failed" << "\n";
  }
}

void Direct::disconnect() {
  *(this->from) = NULL;
  this->connected = false;
}

// Get and set /////////////////////////////////////////////////////////////
