#pragma once

#include "Data/code.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I1_fake : public I1, public Fake {
public:
  // constructor
  I1_fake(Function_stream &out, Return_stream &in);
  I1_fake() : Fake() {}

  //! Destructor
  virtual ~I1_fake() noexcept;

  static Interface *Build_func(Function_stream &os, Return_stream &is) {
    return dynamic_cast<I1 *>(new I1_fake(os, is));
  }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
