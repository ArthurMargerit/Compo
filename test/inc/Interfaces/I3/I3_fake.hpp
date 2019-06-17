#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I3/I3.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I3_fake : public I3, public Fake {
public:
  //! Default constructor
  I3_fake(Function_stream &out, Return_stream &in);

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new I3_fake(os, is);
  }

  //! Destructor
  virtual ~I3_fake() noexcept;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Function_stream &o;
  Return_stream &i;
};
