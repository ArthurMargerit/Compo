#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t3/I_t3.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I_t3_fake : public I_t3, private Fake {
public:
  // constructor
  I_t3_fake(Function_stream &out, Return_stream &in);

  //! Destructor
  virtual ~I_t3_fake() noexcept;

  static Interface *Build_func(Function_stream &os, Return_stream &is) {
    return (I_t3 *)new I_t3_fake(os, is);
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

protected:
private:
};
