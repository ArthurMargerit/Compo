#pragma once

#include <memory>
#include <functional>
#include <iostream>


class Caller;
class Fake;


class Interface
{
public:
  Interface();
  virtual ~Interface();


  virtual Caller* get_caller() = 0;

  //virtual  Fake& get_fake() = 0;

};

std::function<Interface*(std::ostream&,std::istream&)> build_fake(Interface* t);
