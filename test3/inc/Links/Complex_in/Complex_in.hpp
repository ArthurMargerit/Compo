#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Complex_in : public Link

                   ,
                   public Link_to

{

public:
  Complex_in();

  virtual ~Complex_in();

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