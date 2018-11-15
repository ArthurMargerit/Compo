#pragma once

#include "Links/Link.hpp"
#include "Interfaces/Interface.hpp"

class {{NAME}} : public Link
{

public:


  {{NAME}}(){
  }

  {{NAME}}(Interface*& from, Interface* to){

  }

  virtual ~{{NAME}}(){

  }

  virtual void step(){}

  virtual std::string get_name_type(){

  return "{{NAME}}";
  }

};
