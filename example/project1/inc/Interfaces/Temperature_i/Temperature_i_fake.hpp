#pragma once

#include "Data/temperature_sensors.hpp"
#include "Interfaces/Temperature_i/Temperature_i.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Temperature_i_fake : public Temperature_i, protected Fake {
public:
  // constructor
  Temperature_i_fake(Function_stream &out, Return_stream &in);

  //! Destructor
  virtual ~Temperature_i_fake() noexcept;

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new Temperature_i_fake(os, is);
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual Temperature_sample get();

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};
