#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t1/I_t1.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I_t2_caller;

class Fake;
class I_t2_fake;

class I_t2 : public I_t1 {
public:
  using MyCaller = I_t2_caller;
  using MyFake = I_t2_fake;

  virtual Caller *get_caller();

  //! Default constructor
  I_t2();

  //! Destructor
  virtual ~I_t2() noexcept;

  // //! Copy assignment operator
  // I_t2& operator=(const I_t2 &other){}

  // //! Move assignment operator
  // I_t2& operator=(I_t2 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Caller *c;
};

Build_fake_F get_build_fake(I_t2 *t);
