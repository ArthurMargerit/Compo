#include "Links/CompoMe/Posix/Https_client_out/Https_client_out.hpp"

#include "Interfaces/Interface.hpp"

namespace CompoMe {

namespace Posix {

Https_client_out::Https_client_out() : CompoMe::Link() {}

Https_client_out::~Https_client_out() {}

void Https_client_out::step() { Link::step(); }

void Https_client_out::connect() { Link::connect(); }

void Https_client_out::disconnect() { Link::disconnect(); }

// Get and set /////////////////////////////////////////////////////////////

CompoMe::String Https_client_out::get_addr() const { return this->addr; }

void Https_client_out::set_addr(const CompoMe::String p_addr) {
  this->addr = p_addr;
}

CompoMe::String &Https_client_out::a_addr() { return this->addr; }
i32 Https_client_out::get_port() const { return this->port; }

void Https_client_out::set_port(const i32 p_port) { this->port = p_port; }

i32 &Https_client_out::a_port() { return this->port; }
CompoMe::String Https_client_out::get_to_component() const {
  return this->to_component;
}

void Https_client_out::set_to_component(const CompoMe::String p_to_component) {
  this->to_component = p_to_component;
}

CompoMe::String &Https_client_out::a_to_component() {
  return this->to_component;
}
CompoMe::String Https_client_out::get_to_interface() const {
  return this->to_interface;
}

void Https_client_out::set_to_interface(const CompoMe::String p_to_interface) {
  this->to_interface = p_to_interface;
}

CompoMe::String &Https_client_out::a_to_interface() {
  return this->to_interface;
}
CompoMe::String Https_client_out::get_trust_cert() const {
  return this->trust_cert;
}

void Https_client_out::set_trust_cert(const CompoMe::String p_trust_cert) {
  this->trust_cert = p_trust_cert;
}

CompoMe::String &Https_client_out::a_trust_cert() { return this->trust_cert; }

} // namespace Posix

} // namespace CompoMe
