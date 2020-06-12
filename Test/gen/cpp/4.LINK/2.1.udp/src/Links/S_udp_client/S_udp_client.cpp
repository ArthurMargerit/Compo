#include "Links/S_udp_client/S_udp_client.hpp"

#include "Interfaces/Interface.hpp"

namespace c {
#include <arpa/inet.h>
#include <netinet/in.h>

#include <sys/socket.h>
} // namespace c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <unistd.h>

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

#define MAXLINE 1024

S_udp_client::S_udp_client() : Link(), fss(*this), rsr(*this) {}

S_udp_client::~S_udp_client() { this->disconnect(); }

void S_udp_client::step() { Link::step(); }

void S_udp_client::connect() {
  Link::connect();

  long n;
  c::sockaddr_in servaddr;

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_addr.s_addr = c::inet_addr(this->get_addr().c_str());
  servaddr.sin_port = c::htons(this->get_port());
  servaddr.sin_family = AF_INET;

  sockfd = c::socket(AF_INET, c::SOCK_DGRAM, 0);

  auto r = c::connect(sockfd, (c::sockaddr *)&servaddr, sizeof(servaddr));
  if (r == -1) {
    std::cerr << "Connection Error: "<< r << strerror(errno) << "\n";
  }

  this->f = this->a_re->fake_it(fss, rsr);
}

void S_udp_client::disconnect() {
  Link::disconnect();
  if (this->sockfd != -1) {
    close(sockfd);
    this->sockfd = -1;
    delete this->f;
  }
}

// Get and set /////////////////////////////////////////////////////////////

string S_udp_client::get_addr() const { return this->addr; }

void S_udp_client::set_addr(const string p_addr) { this->addr = p_addr; }
int S_udp_client::get_port() const { return this->port; }

void S_udp_client::set_port(const int p_port) { this->port = p_port; }

// Get and set /////////////////////////////////////////////////////////////

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
  buffer[r+1] = '\0';

  std::string str(buffer);
  ss.str(str);
}

void Return_string_stream_recv::end() { ss.str(""); }

Function_string_stream_send::Function_string_stream_send(S_udp_client &l)
    : l(l) {}
Return_string_stream_recv::Return_string_stream_recv(S_udp_client &l) : l(l) {}
