#include "Links/Udp_server/Udp_server.hpp"

Udp_server::Udp_server() {}

Udp_server::~Udp_server() {}

void Udp_server::set_to(Interface *pto) {}

void Udp_server::step() {}

void Udp_server::connect() {}

void Udp_server::disconnect() {}

// Get and set /////////////////////////////////////////////////////////////

String Udp_server::get_addr() const { return addr; }

void Udp_server::set_addr(const String addr) { this->addr = addr; }
ui32 Udp_server::get_port() const { return port; }

void Udp_server::set_port(const ui32 port) { this->port = port; }
