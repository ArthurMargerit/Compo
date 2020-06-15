#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

class Caller;
class Fake;

namespace Car {

namespace Gate {

class Locker_caller;
class Locker_fake;
class Locker : public Interface {
public:
  using MyCaller = Car::Gate::Locker_caller;
  using MyFake = Car::Gate::Locker_fake;

  virtual Caller *get_caller() override;

  //! Default constructor
  Locker();

  //! Destructor
  virtual ~Locker() noexcept;

  // //! Copy assignment operator
  // Locker& operator=(const Locker &other){}

  // //! Move assignment operator
  // Locker& operator=(Locker &&other) noexcept{}
  virtual void open_window() = 0;
  virtual void close_window() = 0;
  virtual string state() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  Caller *c;
};

// Build_fake_F get_build_fake(Car::Gate::Locker* t);

} // namespace Gate

} // namespace Car
