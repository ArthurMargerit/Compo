#pragma once

#include <istream>


class Function_stream_recv {
public:
  virtual std::istream &get_si() = 0;

  virtual void pull() = 0;
  virtual void end() = 0;
  char get() { return this->get_si().get(); }
};

template <typename T>
Function_stream_recv &operator>>(Function_stream_recv &s, T &e) {
  s.get_si() >> e;
  return s;
}


Function_stream_recv &getline(Function_stream_recv &is, std::string &str, char delim);
Function_stream_recv &getline(Function_stream_recv &is, std::string &str);
