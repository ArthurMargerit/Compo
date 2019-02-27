#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

class Return_stream {

public:
  std::istream *si;
  std::ostream *so;

  Return_stream(std::iostream *p_s) : si(p_s), so(p_s) {}
  Return_stream(std::istream *p_s) : si(p_s) {}
  Return_stream(std::ostream *p_s) : so(p_s) {}

  virtual ~Return_stream() {}

  virtual void pull() = 0;
  virtual void end() = 0;
};

template <typename T> Return_stream &operator<<(Return_stream &s, const T &e) {
  *s.so << e;
  return s;
}
template <typename T> Return_stream &operator>>(Return_stream &s, T &e) {
  *s.si >> e;
  return s;
}

class Return_string_stream : public Return_stream {
  using Pull_f = std::function<void(std::stringstream &)>;
  using End_f = std::function<void(std::stringstream &)>;

  std::stringstream sf;
  Pull_f pull;
  End_f end;

  Return_string_stream(Pull_f p_pull, End_f p_end)
      : Return_stream(&sf, &sf), pull(p_pull), end(p_end) {}

  virtual void pull() { this->pull(sf); }
  virtual void end() { this->end(sf); }
}
