#pragma once

#include "Interfaces/org/mpris/MediaPlayer2/Ctl/Ctl.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace org {

namespace mpris {

namespace MediaPlayer2 {

class Ctl_caller_stream : public CompoMe::Caller_stream {
private:
  org::mpris::MediaPlayer2::Ctl &comp;

public:
  Ctl_caller_stream(org::mpris::MediaPlayer2::Ctl &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool Quit(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool Raise(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
};

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
