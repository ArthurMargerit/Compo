#pragma once

#include "Data/test2.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I_t4_caller;

class Fake;
class I_t4_fake;

class I_t4 : public Interface {
public:
  using MyCaller = I_t4_caller;
  using MyFake = I_t4_fake;

  virtual Caller *get_caller();

  //! Default constructor
  I_t4();

  //! Destructor
  virtual ~I_t4() noexcept;

  // //! Copy assignment operator
  // I_t4& operator=(const I_t4 &other){}

  // //! Move assignment operator
  // I_t4& operator=(I_t4 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Caller *c;
};

Build_fake_F get_build_fake(I_t4 *t);
