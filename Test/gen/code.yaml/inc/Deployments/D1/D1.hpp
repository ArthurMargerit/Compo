#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/C/C1.hpp"

#include "Components/C/C1.hpp"

#include "Components/C/C1.hpp"

class D1 : public CompoMe::Deployment {
private:
  // COMPONENT

  C::C1 a;

  C::C1 b;

  C::C1 c;

  // CONNECTOR

  // DATA

  B::i d;

  S1 e;

  S::S2 f;

  // LINK

public:
  D1();
  virtual ~D1();

  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;

  // GET //////////////////////////////////////////////////////////////////////
  // COMPONENT

  C::C1 &get_a();

  C::C1 &get_b();

  C::C1 &get_c();

  // CONNECTOR

  // LINK
};
