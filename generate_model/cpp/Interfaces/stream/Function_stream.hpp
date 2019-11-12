#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

class Function_stream {

private:
  std::istream *si = NULL;
  std::ostream *so = NULL;

public:
  // GET AND SET //////////////////////////////////////////////////////////////
  std::ostream* get_so() const {
    return so;
  }

  void set_so(std::ostream* so) {
    this->so = so;
  }

  std::istream* get_si() const {
    return si;
  }

  void set_si(std::istream* si) {
    this->si = si;
  }

  // CONSTRUCTEUR /////////////////////////////////////////////////////////////
  Function_stream(std::istream *i_s, std::ostream *o_s);
  Function_stream(std::istream *p_s);
  Function_stream(std::ostream *p_s);
  virtual ~Function_stream();

  // FUNCTION /////////////////////////////////////////////////////////////////
  virtual void call() = 0;
  virtual void start() = 0;
  char get();
};

template <typename T>
Function_stream &operator<<(Function_stream &s, const T &e) {
  *s.get_so() << e;
  return s;
}

template <typename T> Function_stream &operator>>(Function_stream &s, T &e) {
  *s.get_si() >> e;
  return s;
}

class Function_string_stream : public Function_stream {
private:
  using Call_f = std::function<void(std::stringstream &)>;
  using Start_f = std::function<void(std::stringstream &)>;

  std::stringstream sf;
  Call_f call_f;
  Start_f start_f;

public:
  Function_string_stream(
      Call_f p_call = [](std::stringstream &) {},
      Start_f p_start = [](std::stringstream &) {});

  virtual void call();
  virtual void start();
};

namespace std {
Function_stream &getline(Function_stream &is, string &str, char delim);
Function_stream &getline(Function_stream &is, string &str);
} // namespace std
