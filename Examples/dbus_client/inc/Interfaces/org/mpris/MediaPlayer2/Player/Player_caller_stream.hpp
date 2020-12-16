#pragma once

#include "Interfaces/org/mpris/MediaPlayer2/Player/Player.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace org {

namespace mpris {

namespace MediaPlayer2 {

class Player_caller_stream : public CompoMe::Caller_stream {
private:
  org::mpris::MediaPlayer2::Player &comp;

public:
  Player_caller_stream(org::mpris::MediaPlayer2::Player &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool Next(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool Previous(CompoMe::Function_stream_recv &is,
                CompoMe::Return_stream_send &os);

  bool PlayPause(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);

  bool Play(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool Pause(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);

  bool OpenUri(CompoMe::Function_stream_recv &is,
               CompoMe::Return_stream_send &os);

  bool Seek(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool Stop(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);
};

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
