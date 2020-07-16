#pragma once

#include "Data/file.hpp"

#include "Interfaces/org/mpris/MediaPlayer2/Player/Player.hpp"

#include "Interfaces/Fake_dbus.hpp"

// class Function_stream_send;
// class Return_stream_recv;

namespace org {

namespace mpris {

namespace MediaPlayer2 {

class Player_fake_dbus : public org::mpris::MediaPlayer2::Player,
                         public CompoMe::Fake_dbus {
public:
  // constructor
  Player_fake_dbus(CompoMe::Function_dbus_send &out,
                   CompoMe::Return_dbus_recv &in);

  //! Destructor
  virtual ~Player_fake_dbus() noexcept;

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual void Next() override;

  virtual void Previous() override;

  virtual void PlayPause() override;

  virtual void Play() override;

  virtual void Pause() override;

  virtual void OpenUri(string Uri) override;

  virtual void Seek(i64 offset) override;

  virtual void Stop() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
