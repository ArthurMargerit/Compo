#pragma once

#include "Data/test2.hpp"
#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Return_stream.hpp"
#include "Links/Link.hpp"
#include <functional>

class Simple : public Link, public Link_direct {

public:
  Simple();

  virtual ~Simple();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  Build_fake_F build_f;

public:
  // Get and set /////////////////////////////////////////////////////////////

  void set_build_f(Build_fake_F);

  virtual void set_from_to(Interface **from, Interface *to);
};