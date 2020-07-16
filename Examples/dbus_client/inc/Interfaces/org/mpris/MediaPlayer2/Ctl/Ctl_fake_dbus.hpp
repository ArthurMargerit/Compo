#pragma once

#include "Data/file.hpp"

#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl.hpp"

#include "Interfaces/Fake_dbus.hpp"

// class Function_stream_send;
// class Return_stream_recv;

namespace org {

namespace mpris {

namespace MediaPlayer2 {

class Ctl_fake_dbus : public org::mpris::MediaPlayer2::Ctl,
                      public CompoMe::Fake_dbus {
public:
  // constructor
  Ctl_fake_dbus(CompoMe::Function_dbus_send &out,
                CompoMe::Return_dbus_recv &in);

  //! Destructor
  virtual ~Ctl_fake_dbus() noexcept;

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
