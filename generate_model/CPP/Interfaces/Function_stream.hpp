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

  Function_stream(std::iostream *p_s) : si(p_s), so(p_s) {}
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
  Call_f call;
  Start_f start;

  Function_string_stream(Call_f p_call, Start_f p_start)
      : Function_stream(&sf, &sf), call(p_call), start(p_call) {}

  virtual void call() { this->call(sf); }
  virtual void start() { this->start(sf); }
}
