#pragma once

#include "Data/file.hpp"

#include "Interfaces/Car/Reporter/Reporter.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace Car {

class Reporter_fake_stream : public Car::Reporter, public CompoMe::Fake_stream {
public:
  // constructor
  Reporter_fake_stream(CompoMe::Function_stream_send &out,
                       CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Reporter_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Car::Reporter*>(new Car::Reporter_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void send_err(i32 err_code, CompoMe::String message) override;

  virtual void send_info(i32 info_code, CompoMe::String message) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace Car
