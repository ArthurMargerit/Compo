#pragma once

#include <functional>
#include <iostream>
#include <memory>

class Caller;
class Fake;
class Function_stream;
class Return_stream;

class Interface {
public:
  Interface();
  virtual ~Interface();
  virtual Caller *get_caller() = 0;
  virtual bool is_fake() { return false; };
};

typedef std::function<Interface *(Function_stream &, Return_stream &)>
    Build_fake_F;

Build_fake_F get_build_fake(Interface *t);