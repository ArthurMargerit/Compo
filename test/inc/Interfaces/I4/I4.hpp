#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I3/I3.hpp"

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class Caller;
class I4_caller;

class Fake;
class I4_fake;

class I4 : public I3 {
public:
  using MyCaller = I4_caller;
  using MyFake = I4_fake;

  Caller *c;

  virtual Caller *get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  I4();

  //! Destructor
  virtual ~I4() noexcept;

  // //! Copy assignment operator
  // I4& operator=(const I4 &other){}

  // //! Move assignment operator
  // I4& operator=(I4 &&other) noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I4 *t);
