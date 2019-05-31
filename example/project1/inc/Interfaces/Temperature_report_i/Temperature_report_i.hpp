#pragma once

#include "Data/temperature_sensors.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

#include "Data/Struct_Temperature_sample.hpp"

class Caller;
class Temperature_report_i_caller;

class Fake;
class Temperature_report_i_fake;

class Temperature_report_i : public Interface {
public:
  using MyCaller = Temperature_report_i_caller;
  using MyFake = Temperature_report_i_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  Temperature_report_i();

  //! Destructor
  virtual ~Temperature_report_i() noexcept;

  // //! Copy assignment operator
  // Temperature_report_i& operator=(const Temperature_report_i &other){}

  // //! Move assignment operator
  // Temperature_report_i& operator=(Temperature_report_i &&other) noexcept{}
  virtual void notify(Temperature_sample ts) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};

std::function<Fake *(Function_stream &, Return_stream &)>
build_fake(Temperature_report_i *t);
