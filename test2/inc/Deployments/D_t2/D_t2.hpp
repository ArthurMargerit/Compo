#pragma once

#include "Deployments/D_t1/D_t1.hpp"

#include "Links/Simple/Simple.hpp"

class D_t2 : public D_t1 {
private:
  Simple s0;

public:
  D_t2();
  virtual ~D_t2();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};