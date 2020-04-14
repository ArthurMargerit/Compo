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

  virtual void f() override;

  virtual void f1() override;

  virtual void f2(i32 a) override;

  virtual void f3(i32 a, i32 b) override;

  virtual i32 f4() override;

  virtual i32 f5(i32 a) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
