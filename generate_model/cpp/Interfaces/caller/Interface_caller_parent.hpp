#pragma once

#include <iostream>
class Function_stream_recv;
class Return_stream_send;

class Caller {
public:
  Caller();
  virtual ~Caller();

  virtual bool call(Function_stream_recv &is, Return_stream_send &os) = 0;
  virtual bool call(std::string &name_function, Function_stream_recv &is,
                    Return_stream_send &os) = 0;
};
