#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Fifo_in : public Link, public Link_to {

public:
  Fifo_in();

  virtual ~Fifo_in();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  String fifo;

  // Get and set /////////////////////////////////////////////////////////////

  virtual String get_fifo() const;

  virtual void set_fifo(const String fifo);

  virtual void set_to(Interface *to);
};