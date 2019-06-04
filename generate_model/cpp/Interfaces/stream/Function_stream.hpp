#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

class Function_stream {

public:
  std::istream *si;
  std::ostream *so;

  std::function<void(void)> f;

  Function_stream(std::istream *i_s, std::ostream *o_s) : si(i_s), so(o_s) {}
  Function_stream(std::istream *p_s) : si(p_s) {}
  Function_stream(std::ostream *p_s) : so(p_s) {}

  virtual ~Function_stream() {}

  virtual void call() = 0;
  virtual void start() = 0;
};

template <typename T>
Function_stream &operator<<(Function_stream &s, const T &e) {
  *s.so << e;
  return s;
}

template <typename T> Function_stream &operator>>(Function_stream &s, T &e) {
  *s.si >> e;
  return s;
}

class Function_string_stream : public Function_stream {
  using Call_f = std::function<void(std::stringstream &)>;
  using Start_f = std::function<void(std::stringstream &)>;

  std::stringstream sf;
  Call_f call_f;
  Start_f start_f;

  Function_string_stream(Call_f p_call, Start_f p_start)
      : Function_stream(&sf, &sf), call_f(p_call), start_f(p_start) {}

  virtual void call() { this->call_f(sf); }
  virtual void start() { this->start_f(sf); }
};

namespace std {
  Function_stream &getline(Function_stream &is, string &str, char delim);
  Function_stream &getline(Function_stream &is, string &str);
}
