#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include "Data/Range.hpp"

#include <functional>

class Caller;
class Fake;

class Sensor_caller;
class Sensor_fake;
class Sensor : public Interface {
public:
  using MyCaller = Sensor_caller;
  using MyFake = Sensor_fake;

  virtual Caller *get_caller() override;

  //! Default constructor
  Sensor();

  //! Destructor
  virtual ~Sensor() noexcept;

  // //! Copy assignment operator
  // Sensor& operator=(const Sensor &other){}

  // //! Move assignment operator
  // Sensor& operator=(Sensor &&other) noexcept{}
  virtual double get_value() = 0;
  virtual Range get_range() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  Caller *c;
};

// Build_fake_F get_build_fake(Sensor* t);
