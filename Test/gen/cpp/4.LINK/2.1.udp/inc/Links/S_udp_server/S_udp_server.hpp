#pragma once

#include "Links/Link.hpp"

class Function_stream;
class Return_stream;
class Interface;

#include "Data/code.hpp"

#include <functional>

class S_udp_server : public CompoMe::Link, public CompoMe::Link_in {
public:
  S_udp_server();
  virtual ~S_udp_server();

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
};
