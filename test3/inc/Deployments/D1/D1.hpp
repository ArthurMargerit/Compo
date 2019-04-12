#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/C1/C1.hpp"

#include "Components/C2/C2.hpp"

#include "Components/C3/C3.hpp"

#include "Links/Simple/Simple.hpp"

class D1 : public Deployment {
private:
  C1::C1 ca;

  C2::C2 cb;

  C3::C3 cc;

  Simple s1;

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