#pragma once

#include "Data/file.hpp"

#include "Interfaces/test/test.hpp"

#include "Interfaces/test_p/test_p_fake.hpp"

class Function_stream_send;
class Return_stream_recv;

class test_fake : public test, public test_p_fake {
public:
  // constructor
  test_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~test_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<test*>(new test_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  // INTERFACE Function test_p //////////////////////////////////////

  virtual void f0() override;

  virtual void f1(double a) override;

  virtual void f2(i8 a) override;

  virtual void f3(i16 a) override;

  virtual void f5(i32 a) override;

  virtual void f6(i64 a) override;

  virtual void f7(u8 a) override;

  virtual void f8(u16 a) override;

  virtual void f9(u32 a) override;

  virtual void f10(u64 a) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  // INTERFACE get/set test_p ////////////////////////////////////////
  virtual i32 get_a() const override;
  virtual void set_a(const i32 &a) override;

  virtual i64 get_b() const override;
  virtual void set_b(const i64 &b) override;
};