#include "Links/Fifo_out/Fifo_out.hpp"

Fifo_out::Fifo_out() {}

Fifo_out::~Fifo_out() {}

void Fifo_out::set_from(Interface **pfrom) {}

void Fifo_out::step() {}

void Fifo_out::connect() {}

void Fifo_out::disconnect() {}

// Get and set /////////////////////////////////////////////////////////////

String Fifo_out::get_fifo() const { return fifo; }

void Fifo_out::set_fifo(const String fifo) { this->fifo = fifo; }
