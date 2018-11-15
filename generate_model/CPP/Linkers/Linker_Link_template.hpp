#pragma once


#include "Links/{{LINK.NAME}}.hpp"

#include "Interfaces/Fake.hpp"
#include "Interfaces/Caller.hpp"

class {{NAME}}_{{LINK.NAME}} : public {{LINK.NAME}}
{
 public:
  {{NAME}}_{{LINK.NAME}}();
  virtual ~{{NAME}}_{{LINK.NAME}}();
};

class {{NAME}}_{{LINK.NAME}}_in : public {{NAME}}_{{LINK.NAME}}
{
  Caller* c;
};

class {{NAME}}_{{LINK.NAME}}_out : public {{NAME}}_{{LINK.NAME}}
{
  Fake* f;
};
