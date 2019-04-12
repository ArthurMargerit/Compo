#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Links/Link.hpp"

class Complex_out_log : public Link

                        ,
                        public Link_from

{

public:
  Complex_out_log();

  virtual ~Complex_out_log();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

  // DATA ////////////////////////////////////////////////////////////////////

  // Get and set /////////////////////////////////////////////////////////////

  virtual void set_from(Interface **from);
};