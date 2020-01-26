#pragma once

#include "Data/base.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I1_caller;

class Fake;
class I1_fake;

class I1 : public Interface {
public:
  using MyCaller = I1_caller;
  using MyFake = I1_fake;

  virtual Caller *get_caller() override;

  //! Default constructor
  I1();

  //! Destructor
  virtual ~I1() noexcept;

  // //! Copy assignment operator
  // I1& operator=(const I1 &other){}

  // //! Move assignment operator
  // I1& operator=(I1 &&other) noexcept{}
  virtual void f1() = 0;
  virtual int f3() = 0;
  virtual void f2(int p1) = 0;
  virtual int f4(int p1) = 0;
  virtual int f5(int p1, int p2) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  virtual int get_a() const = 0;
  virtual void set_a(const int &a) = 0;
  virtual int get_b() const = 0;
  virtual void set_b(const int &b) = 0;

private:
  Caller *c;
};

Build_fake_F get_build_fake(I1 *t);