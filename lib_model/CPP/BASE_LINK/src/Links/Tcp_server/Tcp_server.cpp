#include "Links/Tcp_server/Tcp_server.hpp"

Tcp_server::Tcp_server() {}

Tcp_server::~Tcp_server() {}

void Tcp_server::set_to(Interface *pto) {}

void Tcp_server::step() {}

void Tcp_server::connect() {}

void Tcp_server::disconnect() {}

// Get and set /////////////////////////////////////////////////////////////

String Tcp_server::get_addr() const { return addr; }

void Tcp_server::set_addr(const String addr) { this->addr = addr; }
ui32 Tcp_server::get_port() const { return port; }

void Tcp_server::set_port(const ui32 port) { this->port = port; }
