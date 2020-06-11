#pragma once

#include "Data/code.hpp"

#include "Interfaces/I1/I1.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

class I1_fake : public I1, public Fake {
public:
  // constructor
  I1_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~I1_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<I1*>(new I1_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void f1() override;

  virtual int f2() override;

  virtual int f3(int a) override;

  virtual int f4(int a, int b) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
