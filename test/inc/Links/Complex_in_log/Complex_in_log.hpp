#pragma once

#include "Data/test.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Complex_in_log : public Link, public Link_to {

public:
  Complex_in_log();

  virtual ~Complex_in_log();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  mstring name;

  int port;

  // Get and set /////////////////////////////////////////////////////////////

  virtual mstring get_name() const;

  virtual void set_name(const mstring name);
  virtual int get_port() const;

  virtual void set_port(const int port);

  virtual void set_to(Interface *to);
};