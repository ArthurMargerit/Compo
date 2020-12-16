#pragma once

#include "Data/CompoMe_esp32.hpp"

#include "Interfaces/Embded/IO/Pin_in/Pin_in.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace Embded {

namespace IO {

class Pin_in_fake_stream : public Embded::IO::Pin_in,
                           public CompoMe::Fake_stream {
public:
  // constructor
  Pin_in_fake_stream(CompoMe::Function_stream_send &out,
                     CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Pin_in_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Embded::IO::Pin_in*>(new
  //   Embded::IO::Pin_in_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual Embded::IO::Pin_State get_state() const override;
  virtual void set_state(const Embded::IO::Pin_State &state) override;
};

} // namespace IO

} // namespace Embded
