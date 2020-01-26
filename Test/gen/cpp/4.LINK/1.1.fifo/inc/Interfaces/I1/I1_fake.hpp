#pragma once

#include "Data/base.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I1_fake : public I1, public Fake {
public:
  // constructor
  I1_fake(Function_stream &out, Return_stream &in);
  I1_fake() {}

  //! Destructor
  virtual ~I1_fake() noexcept;

  static Interface *Build_func(Function_stream &os, Return_stream &is) {
    return dynamic_cast<I1 *>(new I1_fake(os, is));
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void f1() override;

  virtual int f3() override;

  virtual void f2(int p1) override;

  virtual int f4(int p1) override;

  virtual int f5(int p1, int p2) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual int get_a() const override;
  virtual void set_a(const int &a) override;

  virtual int get_b() const override;
  virtual void set_b(const int &b) override;
};