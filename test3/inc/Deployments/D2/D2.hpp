#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/C2/C2.hpp"

#include "Components/C4/C4.hpp"

#include "Components/C4/C4.hpp"

#include "Components/C4/C4.hpp"

#include "Components/C4/C4.hpp"

#include "Links/Simple/Simple.hpp"

class D2 : public Deployment {
private:
  C2::C2 ca;

  C4::C4 cb1;

  C4::C4 cb2;

  C4::C4 cb3;

  C4::C4 cb4;

  Simple s1;

public:
  D2();
  virtual ~D2();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};