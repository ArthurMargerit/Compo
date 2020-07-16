#pragma once

#include <ostream>
#include <string>

namespace CompoMe {

class Return_stream_send {
public:
  virtual std::ostream &get_so() = 0;

  virtual void start() = 0;
  virtual void send() = 0;
};

} // namespace CompoMe


template <typename T>
CompoMe::Return_stream_send &operator<<(CompoMe::Return_stream_send &s, const T &e) {
  s.get_so() << e;
  return s;
}
