#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Fifo_out : public Link, public Link_from {

public:
  Fifo_out();

  virtual ~Fifo_out();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  String fifo;

  // Get and set /////////////////////////////////////////////////////////////

  virtual String get_fifo() const;

  virtual void set_fifo(const String fifo);

  virtual void set_from(Interface **from);
};