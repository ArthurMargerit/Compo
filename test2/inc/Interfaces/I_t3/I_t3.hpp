#pragma once

#include "Data/test2.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I_t3_caller;

class Fake;
class I_t3_fake;

class I_t3 : public Interface {
public:
  using MyCaller = I_t3_caller;
  using MyFake = I_t3_fake;

  virtual Caller *get_caller();

  //! Default constructor
  I_t3();

  //! Destructor
  virtual ~I_t3() noexcept;

  // //! Copy assignment operator
  // I_t3& operator=(const I_t3 &other){}

  // //! Move assignment operator
  // I_t3& operator=(I_t3 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Caller *c;
};

Build_fake_F get_build_fake(I_t3 *t);
