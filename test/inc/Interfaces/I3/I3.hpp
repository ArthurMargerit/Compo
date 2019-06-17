#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I2/I2.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I3_caller;

class Fake;
class I3_fake;

class I3 : public I2 {
public:
  using MyCaller = I3_caller;
  using MyFake = I3_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  I3();

  //! Destructor
  virtual ~I3() noexcept;

  // //! Copy assignment operator
  // I3& operator=(const I3 &other){}

  // //! Move assignment operator
  // I3& operator=(I3 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I3 *t);
