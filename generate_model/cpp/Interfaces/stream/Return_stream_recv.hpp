#pragma once

#include <istream>

class Return_stream_recv {
public:
  virtual std::istream &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
};

template <typename T>
Return_stream_recv &operator>>(Return_stream_recv &s, T &e) {
  s.get_si() >> e;
  return s;
}
