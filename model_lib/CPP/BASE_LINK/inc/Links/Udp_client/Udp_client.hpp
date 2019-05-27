#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Udp_client : public Link, public Link_from {

public:
  Udp_client();

  virtual ~Udp_client();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  String addr;

  ui32 port;

  // Get and set /////////////////////////////////////////////////////////////

  virtual String get_addr() const;

  virtual void set_addr(const String addr);
  virtual ui32 get_port() const;

  virtual void set_port(const ui32 port);

  virtual void set_from(Interface **from);
};
