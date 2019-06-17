#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I4/I4.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I4_fake : public I4, public Fake {
public:
  //! Default constructor
  I4_fake(Function_stream &out, Return_stream &in);

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new I4_fake(os, is);
  }

  //! Destructor
  virtual ~I4_fake() noexcept;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Function_stream &o;
  Return_stream &i;
};
