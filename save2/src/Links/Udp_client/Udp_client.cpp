#include "Links/Udp_client/Udp_client.hpp"

Udp_client::Udp_client() {}

Udp_client::~Udp_client() {}

void Udp_client::set_from(Interface **pfrom) {}

void Udp_client::step() {}

void Udp_client::connect() {}

void Udp_client::disconnect() {}

// Get and set /////////////////////////////////////////////////////////////
string Udp_client::get_addr() const { return addr; }
void Udp_client::set_addr(const string addr) { this->addr = addr; }
uint Udp_client::get_port() const { return port; }
void Udp_client::set_port(const uint port) { this->port = port; }
