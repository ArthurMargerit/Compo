#include "Links/CompoMe/WebSocket/Server/Server.hpp"

namespace CompoMe {

namespace WebSocket {

// addr //////////////////////////////////////////////////////////////
CompoMe::String Server::get_addr() const { return this->addr; }

void Server::set_addr(const CompoMe::String p_addr) { this->addr = p_addr; }

CompoMe::String &Server::a_addr() { return this->addr; }
// port //////////////////////////////////////////////////////////////
i32 Server::get_port() const { return this->port; }

void Server::set_port(const i32 p_port) { this->port = p_port; }

i32 &Server::a_port() { return this->port; }
// maxConnection //////////////////////////////////////////////////////////////
i32 Server::get_maxConnection() const { return this->maxConnection; }

void Server::set_maxConnection(const i32 p_maxConnection) {
  this->maxConnection = p_maxConnection;
}

i32 &Server::a_maxConnection() { return this->maxConnection; }
// Timeout //////////////////////////////////////////////////////////////
i32 Server::get_Timeout() const { return this->Timeout; }

void Server::set_Timeout(const i32 p_Timeout) { this->Timeout = p_Timeout; }

i32 &Server::a_Timeout() { return this->Timeout; }
// ping_auto //////////////////////////////////////////////////////////////
bool Server::get_ping_auto() const { return this->ping_auto; }

void Server::set_ping_auto(const bool p_ping_auto) {
  this->ping_auto = p_ping_auto;
}

bool &Server::a_ping_auto() { return this->ping_auto; }
// ping_interval //////////////////////////////////////////////////////////////
i32 Server::get_ping_interval() const { return this->ping_interval; }

void Server::set_ping_interval(const i32 p_ping_interval) {
  this->ping_interval = p_ping_interval;
}

i32 &Server::a_ping_interval() { return this->ping_interval; }
// ssl //////////////////////////////////////////////////////////////
bool Server::get_ssl() const { return this->ssl; }

void Server::set_ssl(const bool p_ssl) { this->ssl = p_ssl; }

bool &Server::a_ssl() { return this->ssl; }
// to //////////////////////////////////////////////////////////////
CompoMe::String Server::get_to() const { return this->to; }

void Server::set_to(const CompoMe::String p_to) { this->to = p_to; }

CompoMe::String &Server::a_to() { return this->to; }
// ca_cert_file //////////////////////////////////////////////////////////////
CompoMe::String Server::get_ca_cert_file() const { return this->ca_cert_file; }

void Server::set_ca_cert_file(const CompoMe::String p_ca_cert_file) {
  this->ca_cert_file = p_ca_cert_file;
}

CompoMe::String &Server::a_ca_cert_file() { return this->ca_cert_file; }

} // namespace WebSocket

} // namespace CompoMe
