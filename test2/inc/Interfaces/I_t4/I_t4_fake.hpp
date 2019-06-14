#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t4/I_t4.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I_t4_fake : public I_t4, private Fake {
public:
  // constructor
  I_t4_fake(Function_stream &out, Return_stream &in);

  //! Destructor
  virtual ~I_t4_fake() noexcept;

  static Interface *Build_func(Function_stream &os, Return_stream &is) {
    return (I_t4 *)new I_t4_fake(os, is);
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
