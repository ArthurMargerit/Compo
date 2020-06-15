#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

class Caller;
class Fake;

namespace Car {

namespace Gate {

class Window_caller;
class Window_fake;
class Window : public Interface {
public:
  using MyCaller = Car::Gate::Window_caller;
  using MyFake = Car::Gate::Window_fake;

  virtual Caller *get_caller() override;

  //! Default constructor
  Window();

  //! Destructor
  virtual ~Window() noexcept;

  // //! Copy assignment operator
  // Window& operator=(const Window &other){}

  // //! Move assignment operator
  // Window& operator=(Window &&other) noexcept{}
  virtual void lock() = 0;
  virtual void unlock() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual ui8 get_percent() const = 0;
  virtual void set_percent(const ui8 &percent) = 0;

private:
  Caller *c;
};

// Build_fake_F get_build_fake(Car::Gate::Window* t);

} // namespace Gate

} // namespace Car
