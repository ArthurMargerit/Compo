#pragma once

#include "Links/Link.hpp"

class Function_stream;
class Return_stream;
class Interface;

#include "Data/code.hpp"

#include <functional>

class S_udp_client : public Link, public Link_out {
public:
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
  Function_string_stream_recv* fss;
  Return_string_stream_send* rss;
};
