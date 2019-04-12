#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I2_caller;

class Fake;
class I2_fake;

class I2 : public Interface {
public:
  using MyCaller = I2_caller;
  using MyFake = I2_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  I2();

  //! Destructor
  virtual ~I2() noexcept;

  // //! Copy assignment operator
  // I2& operator=(const I2 &other){}

  // //! Move assignment operator
  // I2& operator=(I2 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I2 *t);
