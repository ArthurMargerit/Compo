#pragma once

#include <memory>
#include <functional>
#include <iostream>


class Caller;
class Fake;
class Function_stream;
class Return_stream;


class Interface
{
public:
  Interface();
  virtual ~Interface();


  virtual Caller* get_caller() = 0;

  //virtual  Fake& get_fake() = 0;

};

typedef std::function<Interface*(Function_stream&, Return_stream&)> Build_fake_F;

Build_fake_F get_build_fake(Interface* t);

