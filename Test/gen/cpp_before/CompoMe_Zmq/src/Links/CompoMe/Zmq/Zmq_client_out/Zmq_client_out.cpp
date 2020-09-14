#include "Links/CompoMe/Zmq/Zmq_client_out/Zmq_client_out.hpp"
#include "Interfaces/Interface.hpp"
#include <iostream>
#include <zmq.h>

namespace CompoMe {

namespace Zmq {

Zmq_client_out::Zmq_client_out() : CompoMe::Link(), fss(*this), rsr(*this) {
  a_context = zmq_ctx_new();
  a_requester = zmq_socket(a_context, ZMQ_REQ);
}

Zmq_client_out::~Zmq_client_out() {}

void Zmq_client_out::step() { Link::step(); }

void Zmq_client_out::connect() {
  Link::connect();
  zmq_connect(this->a_requester, this->a_addr.str.c_str());

  this->f = this->a_re->fake_stream_it(fss, rsr);
}

void Zmq_client_out::disconnect() {
  Link::disconnect();
  zmq_close(this->a_requester);
  zmq_ctx_destroy(this->a_context);
}

void Zmq_client_out::set_destination(CompoMe::String addr) {
  this->a_addr = addr;
  return;
}

// Get and set /////////////////////////////////////////////////////////////

// stream
Return_string_stream_recv::Return_string_stream_recv(Zmq_client_out &p_l)
    : CompoMe::Return_stream_recv(), a_l(p_l) {}

void Return_string_stream_recv::pull() {
  char l_buffer[1024 + 2];
  auto e = zmq_recv(this->a_l.get_sock(), l_buffer, 1024, 0);

  l_buffer[e] = ' ';
  l_buffer[e+1] = '\0';
  std::string str(l_buffer);
  this->a_ss.str(str);
}

void Return_string_stream_recv::end() { this->a_ss.str(""); }

Function_string_stream_send::Function_string_stream_send(Zmq_client_out &p_l)
    : a_l(p_l) {}
void Function_string_stream_send::start() { this->a_ss.str(""); }
void Function_string_stream_send::send() {
  zmq_send(this->a_l.get_sock(), this->a_ss.str().c_str(),
           this->a_ss.str().size(), 0);
}
} // namespace Zmq

} // namespace CompoMe
