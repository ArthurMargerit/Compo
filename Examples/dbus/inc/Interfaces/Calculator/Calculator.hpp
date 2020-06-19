#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

class Caller;
class Calculator_caller;

class Fake;
class Calculator_fake;

class Dbus_adapter;
class Calculator_Dbus_adapter;

class Calculator : public Interface {
public:
  using MyFake = Calculator_fake;

  using MyCaller = Calculator_caller;

  using MyDbus_adapter = Calculator_Dbus_adapter;

  virtual Caller *get_caller() override;

  Dbus_adapter *get_dbus_adapter() override;

  //! Default constructor
  Calculator();

  //! Destructor
  virtual ~Calculator() noexcept;

  // //! Copy assignment operator
  // Calculator& operator=(const Calculator &other){}

  // //! Move assignment operator
  // Calculator& operator=(Calculator &&other) noexcept{}
  virtual double add(double a, double b) = 0;
  virtual double sub(double a, double b) = 0;
  virtual double time(double a, double b) = 0;
  virtual double div(double a, double b) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  Caller *c;

  Dbus_adapter *c_dbus;
};

// Build_fake_F get_build_fake(Calculator* t);
