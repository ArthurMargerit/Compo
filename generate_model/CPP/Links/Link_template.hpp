#pragma once

#include "Links/Link.hpp"
#include "Interfaces/Interface.hpp"

template<typename T>
class {{NAME}} : public Link
{

public:

  {{NAME}}(T*& from, T* to){

  }

  virtual ~{{NAME}}(){

  }

  virtual std::string get_name_type(){

  return "{{NAME}}";
  }

};
