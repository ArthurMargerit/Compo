#include "Links/CompoMe/Posix/Udp_client_out/Udp_client_out.hpp"

#include "Interfaces/Interface.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
namespace CompoMe {

namespace Posix {

Udp_client_out::Udp_client_out() : CompoMe::Link(), fss(*this), rsr(*this) {}

Udp_client_out::~Udp_client_out() { this->disconnect(); }

void Udp_client_out::step() { Link::step(); }

void Udp_client_out::connect() {
  Link::connect();
  long n;
  c::sockaddr_in servaddr;

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_addr.s_addr = c::inet_addr(this->get_addr().str.c_str());
  servaddr.sin_port = c::htons(this->get_port());
  servaddr.sin_family = AF_INET;

  sockfd = c::socket(AF_INET, c::SOCK_DGRAM, 0);

  auto r = c::connect(sockfd, (c::sockaddr *)&servaddr, sizeof(servaddr));
  if (r == -1) {
    std::cerr << "Connection Error: " << r << strerror(errno) << "\n";
  }

  this->f = this->a_re->fake_stream_it(fss, rsr);
}

void Udp_client_out::disconnect() {
  Link::disconnect();
  if (this->sockfd != -1) {
    close(sockfd);
    this->sockfd = -1;
    delete this->f;
  }
}
// Get and set /////////////////////////////////////////////////////////////

CompoMe::String Udp_client_out::get_addr() const { return this->addr; }

void Udp_client_out::set_addr(const CompoMe::String p_addr) {
  this->addr = p_addr;
}
i32 Udp_client_out::get_port() const { return this->port; }

void Udp_client_out::set_port(const i32 p_port) { this->port = p_port; }

// stream /////////////////////////////////////////////////////////////

void Function_string_stream_send::send() {

  c::sendto(this->l.get_sockfd(), ss.str().c_str(), ss.str().size(), 0,
            (c::sockaddr *)NULL, 0);
}

void Function_string_stream_send::start() { ss.str(""); }

void Return_string_stream_recv::pull() {
  char buffer[1024];
  int r = c::recvfrom(this->l.get_sockfd(), buffer, 1022, 0,
                      (c::sockaddr *)NULL, NULL);
  if (r == -1) {
    std::cerr << "Error: for udp connection" << strerror(errno) << "\n";
  }
  buffer[r] = ' ';
  buffer[r + 1] = '\0';

  std::string str(buffer);
  ss.str(str);
}

void Return_string_stream_recv::end() { ss.str(""); }

Function_string_stream_send::Function_string_stream_send(Udp_client_out &l)
    : l(l) {}
Return_string_stream_recv::Return_string_stream_recv(Udp_client_out &l) : l(l) {}

} // namespace Posix

} // namespace CompoMe
