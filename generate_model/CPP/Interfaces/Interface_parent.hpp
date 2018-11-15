#pragma once

#include <memory>
class Caller;
class Fake;


class Interface
{
public:
  Interface();
  virtual ~Interface();


  //virtual Caller* get_caller() = 0;
  //virtual  Fake& get_fake() = 0;

};

