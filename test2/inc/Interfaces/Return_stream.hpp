#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

class Return_stream {

public:
  std::istream *si;
  std::ostream *so;

  Return_stream(std::istream *i_s, std::ostream *o_s) : si(i_s), so(o_s) {}
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
  Pull_f pull_f;
  End_f end_f;

  Return_string_stream(Pull_f p_pull, End_f p_end)
      : Return_stream(&sf, &sf), pull_f(p_pull), end_f(p_end) {}

  virtual void pull() { this->pull_f(sf); }
  virtual void end() { this->end_f(sf); }
};

namespace std {
Return_stream &getline(Return_stream &is, string &str, char delim);
Return_stream &getline(Return_stream &is, string &str);
}