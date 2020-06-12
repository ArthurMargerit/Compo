#pragma once

#include "Links/Link.hpp"
namespace c {
#include <arpa/inet.h>
#include <netinet/in.h>

#include <sys/socket.h>
} // namespace c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

class S_udp_client;
class Function_stream;
class Return_stream;
class Interface;

#include "Data/code.hpp"

#include <functional>

class Function_string_stream_send : public Function_stream_send {
public:
  std::stringstream ss;
  S_udp_client &l;

  Function_string_stream_send(S_udp_client &l);
  void start() override;
  void send() override;
  std::ostream &get_so() override { return this->ss; }
};

class Return_string_stream_recv : public Return_stream_recv {
public:
  std::stringstream ss;
  S_udp_client &l;

  Return_string_stream_recv(S_udp_client &l);
  void pull() override;
  void end() override;
  std::istream &get_si() override { return this->ss; }
};

class S_udp_client : public Link, public Link_out {
public:
  int get_sockfd() const {
    return sockfd;
  }

  S_udp_client();
  virtual ~S_udp_client();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // Get and set /////////////////////////////////////////////////////////////

  virtual string get_addr() const;
  virtual void set_addr(const string addr);
  virtual int get_port() const;
  virtual void set_port(const int port);

private:
  // DATA ////////////////////////////////////////////////////////////////////

  string addr;

  int port;

  int sockfd;

  Fake *f;
  Function_string_stream_send fss;
  Return_string_stream_recv rsr;
};
