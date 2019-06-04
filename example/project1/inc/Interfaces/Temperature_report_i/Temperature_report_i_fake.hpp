#pragma once

#include "Data/temperature_sensors.hpp"
#include "Interfaces/Temperature_report_i/Temperature_report_i.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Temperature_report_i_fake : public Temperature_report_i, protected Fake {
public:
  // constructor
  Temperature_report_i_fake(Function_stream &out, Return_stream &in);

  //! Destructor
  virtual ~Temperature_report_i_fake() noexcept;

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new Temperature_report_i_fake(os, is);
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void notify(Temperature_sample ts);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};
