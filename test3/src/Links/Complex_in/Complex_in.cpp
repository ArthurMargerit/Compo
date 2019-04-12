#include "Links/Complex_in/Complex_in.hpp"

Complex_in::Complex_in() {}

Complex_in::~Complex_in() {}

void Complex_in::set_to(Interface *pto) {}

void Complex_in::step() {}

void Complex_in::connect() {}

void Complex_in::disconnect() {}

// Get and set /////////////////////////////////////////////////////////////

mstring Complex_in::get_name() const { return name; }

void Complex_in::set_name(const mstring name) { this->name = name; }
int Complex_in::get_port() const { return port; }

void Complex_in::set_port(const int port) { this->port = port; }
