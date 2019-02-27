#pragma once

class Function_stream {

public:
  std::istream *si;
  std::ostream *so;

  std::function<void(void)> f;

  Function_stream(std::iostream *p_s) : si(p_s), so(p_s) {}
  Function_stream(std::istream *p_s) : si(p_s) {}
  Function_stream(std::ostream *p_s) : so(p_s) {}

  virtual ~Function_stream() {}

  virtual void call() {}
  virtual void start() {}
};

class Return_stream {

public:
  std::istream *si;
  std::ostream *so;

  Return_stream(std::iostream *p_s) : si(p_s), so(p_s) {}
  Return_stream(std::istream *p_s) : si(p_s) {}
  Return_stream(std::ostream *p_s) : so(p_s) {}

  virtual ~Return_stream() {}

  virtual void pull() {}
  virtual void end() {}
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

template <typename T> Return_stream &operator<<(Return_stream &s, const T &e) {
  *s.so << e;
  return s;
}
template <typename T> Return_stream &operator>>(Return_stream &s, T &e) {
  *s.si >> e;
  return s;
}
