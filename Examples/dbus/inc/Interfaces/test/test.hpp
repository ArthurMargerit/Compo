#pragma once

#include "Data/file.hpp"

#include "Interfaces/test_p/test_p.hpp"

#include <functional>

class Caller;
class test_caller;

class Fake;
class test_fake;

class Dbus_adapter;
class test_Dbus_adapter;

class test : public test_p {
public:
  using MyFake = test_fake;

  using MyCaller = test_caller;

  using MyDbus_adapter = test_Dbus_adapter;

  virtual Caller *get_caller() override;

  Dbus_adapter *get_dbus_adapter() override;

  //! Default constructor
  test();

  //! Destructor
  virtual ~test() noexcept;

  // //! Copy assignment operator
  // test& operator=(const test &other){}

  // //! Move assignment operator
  // test& operator=(test &&other) noexcept{}
  virtual void f7(u8 a) = 0;
  virtual void f8(u16 a) = 0;
  virtual void f9(u32 a) = 0;
  virtual void f10(u64 a) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual i32 get_a() const = 0;
  virtual void set_a(const i32 &a) = 0;
  virtual i64 get_b() const = 0;
  virtual void set_b(const i64 &b) = 0;

private:
  Caller *c;

  Dbus_adapter *c_dbus;
};

// Build_fake_F get_build_fake(test* t);
