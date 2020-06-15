#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

class Caller;
class Fake;

namespace Car {

class Reporter_caller;
class Reporter_fake;
class Reporter : public Interface {
public:
  using MyCaller = Car::Reporter_caller;
  using MyFake = Car::Reporter_fake;

  virtual Caller *get_caller() override;

  //! Default constructor
  Reporter();

  //! Destructor
  virtual ~Reporter() noexcept;

  // //! Copy assignment operator
  // Reporter& operator=(const Reporter &other){}

  // //! Move assignment operator
  // Reporter& operator=(Reporter &&other) noexcept{}
  virtual void send_err(int err_code, string message) = 0;
  virtual void send_info(int info_code, string message) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  Caller *c;
};

// Build_fake_F get_build_fake(Car::Reporter* t);

} // namespace Car
