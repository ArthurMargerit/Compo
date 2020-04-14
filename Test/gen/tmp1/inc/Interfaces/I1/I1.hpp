#pragma once

#include "Data/code.hpp"

#include "Interfaces/Interface.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

#include <functional>
class Caller;
class Fake;

class I1_caller;
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
  virtual void f() = 0;
  virtual void f1() = 0;
  virtual void f2(i32 a) = 0;
  virtual void f3(i32 a, i32 b) = 0;
  virtual i32 f4() = 0;
  virtual i32 f5(i32 a) = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  Caller *c;
};

Build_fake_F get_build_fake(I1 *t);
