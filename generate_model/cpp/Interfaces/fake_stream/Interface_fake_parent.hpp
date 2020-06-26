#pragma once

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

class Fake_stream {
public:
  Return_stream_recv &get_i() const { return a_i;}
  Function_stream_send &get_o() const { return a_o;}

  Fake_stream(Function_stream_send &, Return_stream_recv &);
  virtual ~Fake_stream();

private:
  Function_stream_send &a_o;
  Return_stream_recv &a_i;
};
