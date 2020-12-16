#pragma once

#include "Data/file.hpp"

#include "Interfaces/Hello_I/Hello_I.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Hello_I_fake_stream : public Hello_I, public CompoMe::Fake_stream {
public:
  // constructor
  Hello_I_fake_stream(CompoMe::Function_stream_send &out,
                      CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Hello_I_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Hello_I*>(new Hello_I_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual CompoMe::String hello(CompoMe::String who) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
