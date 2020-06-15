#pragma once

#include "Data/file.hpp"

#include "Interfaces/Car/Reporter/Reporter.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

namespace Car {

class Reporter_fake : public Car::Reporter, public Fake {
public:
  // constructor
  Reporter_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~Reporter_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Car::Reporter*>(new Car::Reporter_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void send_err(int err_code, string message) override;

  virtual void send_info(int info_code, string message) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace Car
