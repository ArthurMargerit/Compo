#include "Links/CompoMe/Posix/HttpV2_server_in/HttpV2_server_in.hpp"

#include "Interfaces/Interface.hpp"

namespace CompoMe {

namespace Posix {

HttpV2_server_in::HttpV2_server_in() : CompoMe::Link() {}

HttpV2_server_in::~HttpV2_server_in() {}

void HttpV2_server_in::step() { Link::step(); }

void HttpV2_server_in::connect() { Link::connect(); }

void HttpV2_server_in::disconnect() { Link::disconnect(); }

// Get and set /////////////////////////////////////////////////////////////

CompoMe::String HttpV2_server_in::get_addr() const { return this->addr; }

void HttpV2_server_in::set_addr(const CompoMe::String p_addr) {
  this->addr = p_addr;
}

CompoMe::String &HttpV2_server_in::a_addr() { return this->addr; }
i32 HttpV2_server_in::get_port() const { return this->port; }

void HttpV2_server_in::set_port(const i32 p_port) { this->port = p_port; }

i32 &HttpV2_server_in::a_port() { return this->port; }
ui32 HttpV2_server_in::get_max_client() const { return this->max_client; }

void HttpV2_server_in::set_max_client(const ui32 p_max_client) {
  this->max_client = p_max_client;
}

ui32 &HttpV2_server_in::a_max_client() { return this->max_client; }
ui32 HttpV2_server_in::get_max_request_size() const {
  return this->max_request_size;
}

void HttpV2_server_in::set_max_request_size(const ui32 p_max_request_size) {
  this->max_request_size = p_max_request_size;
}

ui32 &HttpV2_server_in::a_max_request_size() { return this->max_request_size; }

} // namespace Posix

} // namespace CompoMe
