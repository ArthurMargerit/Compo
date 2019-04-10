#include "Links/Fifo_in/Fifo_in.hpp"

Fifo_in::Fifo_in() {}

Fifo_in::~Fifo_in() {}

void Fifo_in::set_to(Interface *pto) {}

void Fifo_in::step() {}

void Fifo_in::connect() {}

void Fifo_in::disconnect() {}

// Get and set /////////////////////////////////////////////////////////////

String Fifo_in::get_fifo() const { return fifo; }

void Fifo_in::set_fifo(const String fifo) { this->fifo = fifo; }
