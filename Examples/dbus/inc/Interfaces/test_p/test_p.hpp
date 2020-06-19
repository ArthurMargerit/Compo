#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

class Caller;
class test_p_caller;

class Fake;
class test_p_fake;

class Dbus_adapter;
class test_p_Dbus_adapter;

class test_p : public Interface {
public:
  using MyFake = test_p_fake;

  using MyCaller = test_p_caller;

  using MyDbus_adapter = test_p_Dbus_adapter;

  virtual Caller *get_caller() override;

  Dbus_adapter *get_dbus_adapter() override;

  //! Default constructor
  test_p();

  //! Destructor
  virtual ~test_p() noexcept;

  // //! Copy assignment operator
  // test_p& operator=(const test_p &other){}

  // //! Move assignment operator
  // test_p& operator=(test_p &&other) noexcept{}
  virtual void f0() = 0;
  virtual void f1(double a) = 0;
  virtual void f2(i8 a) = 0;
  virtual void f3(i16 a) = 0;
  virtual void f5(i32 a) = 0;
  virtual void f6(i64 a) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  Caller *c;

  Dbus_adapter *c_dbus;
};

// Build_fake_F get_build_fake(test_p* t);
