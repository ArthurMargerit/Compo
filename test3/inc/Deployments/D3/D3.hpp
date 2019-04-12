#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/C4/C4.hpp"

#include "Components/C5/C5.hpp"

#include "Components/C4/C4.hpp"

#include "Components/C5/C5.hpp"

#include "Components/C6/C6.hpp"

#include "Components/C6/C6.hpp"

#include "Components/C6/C6.hpp"

#include "Components/C6/C6.hpp"

#include "Links/Simple/Simple.hpp"

#include "Links/Complex_in/Complex_in.hpp"

#include "Links/Complex_out/Complex_out.hpp"

#include "Links/Complex_in/Complex_in.hpp"

#include "Links/Complex_out/Complex_out.hpp"

class D3 : public Deployment {
private:
  C4::C4 ca;

  C5::C5 cb;

  C4::C4 ca2;

  C5::C5 cb2;

  C6::C6 cc;

  C6::C6 cc2;

  C6::C6 cc4;

  C6::C6 cc3;

  Simple s1;

  Complex_in s2;

  Complex_out s3;

  Complex_in s4;

  Complex_out s5;

public:
  D3();
  virtual ~D3();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};