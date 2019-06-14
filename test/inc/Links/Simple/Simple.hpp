#pragma once

#include "Data/test.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Simple : public Link, public Link_direct {

public:
  Simple();

  virtual ~Simple();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  // Get and set /////////////////////////////////////////////////////////////

  virtual void set_from_to(Interface **from, Interface *to);
};