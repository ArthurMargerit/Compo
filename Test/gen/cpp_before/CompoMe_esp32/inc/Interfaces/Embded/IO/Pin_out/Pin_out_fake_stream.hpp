#pragma once

#include "Data/CompoMe_esp32.hpp"

#include "Interfaces/Embded/IO/Pin_out/Pin_out.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace Embded {

namespace IO {

class Pin_out_fake_stream : public Embded::IO::Pin_out,
                            public CompoMe::Fake_stream {
public:
  // constructor
  Pin_out_fake_stream(CompoMe::Function_stream_send &out,
                      CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Pin_out_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Embded::IO::Pin_out*>(new
  //   Embded::IO::Pin_out_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void on() override;

  virtual void off() override;

  virtual void set(Embded::IO::Pin_State ps) override;

  virtual void switch_v() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual Embded::IO::Pin_State get_state() const override;
  virtual void set_state(const Embded::IO::Pin_State &state) override;
};

} // namespace IO

} // namespace Embded
