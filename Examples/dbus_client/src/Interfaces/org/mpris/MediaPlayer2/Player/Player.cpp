
#include "Interfaces/org/mpris/MediaPlayer2/Player/Player.hpp"

namespace org {

namespace mpris {

namespace MediaPlayer2 {

Player::Player() : a_caller_stream(nullptr) {}

Player::~Player() noexcept {
  if (a_caller_stream != nullptr) {
    delete a_caller_stream;
  }
}

CompoMe::Caller_stream *Player::get_caller_stream() {
  if (a_caller_stream == nullptr) {
    a_caller_stream = new MyCallerStream(*this);
  }
  return a_caller_stream;
}

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
