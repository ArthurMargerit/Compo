#pragma once

#include "Data/file.hpp"

#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace org {

namespace mpris {

namespace MediaPlayer2 {

class Ctl_fake_stream : public org::mpris::MediaPlayer2::Ctl,
                        public CompoMe::Fake_stream {
public:
  // constructor
  Ctl_fake_stream(CompoMe::Function_stream_send &out,
                  CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Ctl_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<org::mpris::MediaPlayer2::Ctl*>(new
  //   org::mpris::MediaPlayer2::Ctl_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void Quit() override;

  virtual void Raise() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
