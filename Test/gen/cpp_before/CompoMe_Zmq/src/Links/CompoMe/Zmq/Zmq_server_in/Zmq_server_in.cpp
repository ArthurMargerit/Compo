#include "Links/CompoMe/Zmq/Zmq_server_in/Zmq_server_in.hpp"
#include "CompoMe/Tools/Call.hpp"
#include "Interfaces/Interface.hpp"
#include <assert.h>
#include <zmq.h>

namespace CompoMe {

namespace Zmq {
#define SIZE_BUFFER (1024 * 4)

Zmq_server_in::Zmq_server_in() : CompoMe::Link() {
  this->a_context = zmq_ctx_new();
  this->a_responder = zmq_socket(this->a_context, ZMQ_REP);
}

Zmq_server_in::~Zmq_server_in() {}

void Zmq_server_in::step() {
  Link::step();
  char buffer[SIZE_BUFFER];
  auto m = zmq_recv(this->a_responder, buffer, SIZE_BUFFER, ZMQ_NOBLOCK);

  // no message
  if (m == -1 && errno == EAGAIN) {
    return;
  }

  auto l_res = CompoMe::Tools::call(&this->get_caller_stream(), std::string(buffer));
  zmq_send(this->a_responder, l_res.second.c_str(), l_res.second.length(), 0);
}

void Zmq_server_in::connect() { Link::connect();
  int rc = zmq_bind(this->a_responder,this->a_addr.str.c_str());
  assert(rc == 0);
}

void Zmq_server_in::disconnect() { Link::disconnect();
  zmq_unbind(this->a_responder, this->a_addr.str.c_str());
}

void Zmq_server_in::bind(CompoMe::String addr) {
  this->a_addr = addr;
  return;
}

void Zmq_server_in::unbind(CompoMe::String addr) {
  int rc = zmq_unbind(this->a_responder, "tcp://*:5555");
  assert(rc == 0);
  return;
}

// Get and set /////////////////////////////////////////////////////////////

} // namespace Zmq

} // namespace CompoMe
