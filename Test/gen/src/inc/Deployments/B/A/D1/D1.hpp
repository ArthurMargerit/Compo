#pragma once

#include "Deployments/Deployment.hpp"

namespace B {

namespace A {

class D1 : public CompoMe::Deployment {
private:
  // COMPONENT

  // CONNECTOR

  // DATA

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

  // CONNECTOR

  // LINK
};

} // namespace A

} // namespace B
