#pragma once

#include "Data/Types.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I2/I2.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I2_fake : public I2, public Fake {
public:
  //! Default constructor
  I2_fake(Function_stream &out, Return_stream &in);

  static Fake *Build_func(Function_stream &os, Return_stream &is) {
    return new I2_fake(os, is);
  }

  //! Destructor
  virtual ~I2_fake() noexcept;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
  Function_stream &o;
  Return_stream &i;
};
