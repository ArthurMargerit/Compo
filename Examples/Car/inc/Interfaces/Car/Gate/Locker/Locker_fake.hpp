#pragma once

#include "Data/file.hpp"

#include "Interfaces/Car/Gate/Locker/Locker.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

namespace Car {

namespace Gate {

class Locker_fake : public Car::Gate::Locker, public Fake {
public:
  // constructor
  Locker_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~Locker_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Car::Gate::Locker*>(new
  //   Car::Gate::Locker_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void open_window() override;

  virtual void close_window() override;

  virtual string state() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace Gate

} // namespace Car
