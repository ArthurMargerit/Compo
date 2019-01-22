
#include "Linkers/Linker.hpp"
#include <iostream>

Linker::Linker() {
  std::cout << "Linker"
            << "\n";
}

Linker::~Linker() {}

void Linker::set_to(Interface *pto) {to = to; }
Interface *Linker::get_to() {return this->to;}
