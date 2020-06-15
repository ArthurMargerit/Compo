#pragma once

#include "Data/file.hpp"

#include "Interfaces/Car/Gate/Window/Window.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

namespace Car {

namespace Gate {

class Window_fake : public Car::Gate::Window, public Fake {
public:
  // constructor
  Window_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~Window_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Car::Gate::Window*>(new
  //   Car::Gate::Window_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void lock() override;

  virtual void unlock() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual ui8 get_percent() const override;
  virtual void set_percent(const ui8 &percent) override;
};

} // namespace Gate

} // namespace Car
