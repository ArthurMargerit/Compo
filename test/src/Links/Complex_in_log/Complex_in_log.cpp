#include "Links/Complex_in_log/Complex_in_log.hpp"

Complex_in_log::Complex_in_log() {}

Complex_in_log::~Complex_in_log() {}

void Complex_in_log::set_to(Interface *pto) {}

void Complex_in_log::step() {}

void Complex_in_log::connect() {}

void Complex_in_log::disconnect() {}

// Get and set /////////////////////////////////////////////////////////////

mstring Complex_in_log::get_name() const { return name; }

void Complex_in_log::set_name(const mstring name) { this->name = name; }
int Complex_in_log::get_port() const { return port; }

void Complex_in_log::set_port(const int port) { this->port = port; }
