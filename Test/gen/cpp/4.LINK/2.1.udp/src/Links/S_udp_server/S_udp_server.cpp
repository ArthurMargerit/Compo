#include "Links/S_udp_server/S_udp_server.hpp"

#include "Interfaces/Interface.hpp"
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

#define MAXLINE 1024

class Return_string_stream_send : public Return_stream_send {
public:
  std::ostream &_os;
  Return_string_stream_send(std::ostream &os) : _os(os) {}
  void start() override {}
  void send() override {}
  std::ostream &get_so() override { return this->_os; }
};

class Function_string_stream_recv : public Function_stream_recv {
public:
  std::istream &_is;
  Function_string_stream_recv(std::istream &is) : _is(is) {}
  void pull() override {}
  void end() override {}
  std::istream &get_si() override { return this->_is; }
};

S_udp_server::S_udp_server() : Link() {}

S_udp_server::~S_udp_server() {}

void S_udp_server::step() {
  Link::step();
  int n = 0;
  char buffer[MAXLINE];
  buffer[0] = '+';
  struct sockaddr_in cliaddr;

  unsigned int len = sizeof(cliaddr);

  n = recvfrom(sockfd, buffer, MAXLINE, MSG_WAITALL, (sockaddr *)&cliaddr,
               &len);

  if (n == -1) {
    return;
  }

  buffer[n] = '\0';

  auto l_so = std::stringstream(buffer);
  auto l_si = std::stringstream();
  Function_string_stream_recv fs_c(l_so);
  Return_string_stream_send rs_c(l_si);

  if (this->connected()) {
    bool r = this->get_caller().call(fs_c, rs_c);
    if (!r) {
      std::cerr << "!Wrong call";
      rs_c.get_so() << "!Wrong call";
    }
  } else {
    std::cerr << "!No Connection";
    rs_c.get_so() << "!No Connection";
  }

  if (strlen(l_si.str().c_str()) == 0) {
    l_si << " ";
  }

  sendto(sockfd, l_si.str().c_str(), strlen(l_si.str().c_str()), 0,
         (sockaddr *)&cliaddr, len);
}

void S_udp_server::connect() {
  Link::connect();
  struct sockaddr_in servaddr;

  std::cout << "connect"
            << "\n";

  // Creating socket file descriptor
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));

  // Filling server information
  servaddr.sin_family = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(this->get_port());

  // Bind the socket with the server address
  if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  long save_file_flags = fcntl(sockfd, F_GETFL);
  save_file_flags |= O_NONBLOCK;
  fcntl(sockfd, F_SETFL, SOCK_NONBLOCK);

  std::cout << "bind"
            << "\n";
}

void S_udp_server::disconnect() { Link::disconnect(); }

// Get and set /////////////////////////////////////////////////////////////

string S_udp_server::get_addr() const { return this->addr; }

void S_udp_server::set_addr(const string p_addr) { this->addr = p_addr; }
int S_udp_server::get_port() const { return this->port; }

void S_udp_server::set_port(const int p_port) { this->port = p_port; }
