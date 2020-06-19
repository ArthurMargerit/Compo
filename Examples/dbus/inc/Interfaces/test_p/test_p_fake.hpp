#pragma once

#include "Data/file.hpp"

#include "Interfaces/test_p/test_p.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

class test_p_fake : public test_p, public Fake {
public:
  // constructor
  test_p_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~test_p_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<test_p*>(new test_p_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void f0() override;

  virtual void f1(double a) override;

  virtual void f2(i8 a) override;

  virtual void f3(i16 a) override;

  virtual void f5(i32 a) override;

  virtual void f6(i64 a) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
