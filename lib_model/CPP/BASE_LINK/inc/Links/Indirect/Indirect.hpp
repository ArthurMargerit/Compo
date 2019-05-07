#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Indirect : public Link, public Link_direct {

public:
  Indirect();

  virtual ~Indirect();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  // Get and set /////////////////////////////////////////////////////////////

  virtual void set_from_to(Interface **from, Interface *to);
};