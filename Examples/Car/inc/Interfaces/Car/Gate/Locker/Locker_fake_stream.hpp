#pragma once

#include "Data/file.hpp"

#include "Interfaces/Car/Gate/Locker/Locker.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace Car {

namespace Gate {

class Locker_fake_stream : public Car::Gate::Locker,
                           public CompoMe::Fake_stream {
public:
  // constructor
  Locker_fake_stream(CompoMe::Function_stream_send &out,
                     CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Locker_fake_stream() noexcept;

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

  virtual CompoMe::String state() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace Gate

} // namespace Car
