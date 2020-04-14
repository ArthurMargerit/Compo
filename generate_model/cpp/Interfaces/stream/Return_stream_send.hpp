#pragma once
#include <ostream>

class Return_stream_send {
public:
  virtual std::ostream &get_so() = 0;

  virtual void start() = 0;
  virtual void send() = 0;
};

template <typename T>
Return_stream_send &operator<<(Return_stream_send &s, const T &e) {
  s.get_so() << e;
  return s;
}
