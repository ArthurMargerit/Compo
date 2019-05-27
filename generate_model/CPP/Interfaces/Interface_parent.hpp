#pragma once

#include <memory>
#include <functional>
#include <iostream>


typedef Build_fake_F std::function<Interface*(std::ostream&,std::istream&)>

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

Build_fake_F get_build_fake(Interface* t);

