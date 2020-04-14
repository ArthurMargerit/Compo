#pragma once
#include "Components/Require_helper.hpp"

class Component {
public:
  Component();
  virtual ~Component();

  virtual void configuration();
  virtual void connection();
  virtual void start();
  virtual void step();
  virtual void stop();
  virtual void status();
};
