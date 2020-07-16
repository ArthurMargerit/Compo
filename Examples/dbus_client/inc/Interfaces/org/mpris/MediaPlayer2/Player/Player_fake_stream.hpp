#pragma once

#include "Data/file.hpp"

#include "Interfaces/org/mpris/MediaPlayer2/Player/Player.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace org {

namespace mpris {

namespace MediaPlayer2 {

class Player_fake_stream : public org::mpris::MediaPlayer2::Player,
                           public CompoMe::Fake_stream {
public:
  // constructor
  Player_fake_stream(CompoMe::Function_stream_send &out,
                     CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Player_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<org::mpris::MediaPlayer2::Player*>(new
  //   org::mpris::MediaPlayer2::Player_fake(os,is));
  // }

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
