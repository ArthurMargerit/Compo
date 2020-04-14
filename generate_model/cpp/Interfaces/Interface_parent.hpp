#pragma once

#include <functional>
#include <iostream>
#include <memory>

class Caller;
class Fake;
class Function_stream_send;
class Return_stream_recv;

class Interface {
public:
  Interface();
  virtual ~Interface();
  virtual Caller *get_caller() = 0;
  virtual bool is_fake() { return false; };
};

typedef std::function<Interface *(Function_stream_send &, Return_stream_recv &)>
    Build_fake_F;

Build_fake_F get_build_fake(Interface *t);
