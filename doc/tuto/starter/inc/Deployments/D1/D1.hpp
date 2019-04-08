#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/Simple_Compo/Simple_Compo.hpp"

class D1 : public Deployment {
private:
  Simple_Compo::Simple_Compo compo;

public:
  D1();
  virtual ~D1();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};