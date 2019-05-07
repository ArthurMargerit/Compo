#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Direct : public Link, public Link_direct {

public:
  Direct();

  virtual ~Direct();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

private:
  Interface **from;
  Interface *to;
  bool connected;
  
  // Get and set /////////////////////////////////////////////////////////////
public:
  virtual void set_from_to(Interface **from, Interface *to);
};
