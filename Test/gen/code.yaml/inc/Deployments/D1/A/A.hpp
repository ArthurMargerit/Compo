#pragma once

#include "Deployments/Deployment.hpp"

namespace D1 {

class A : public CompoMe::Deployment {
private:
  // COMPONENT

  // CONNECTOR

  // DATA

  // LINK

public:
  A();
  virtual ~A();

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

} // namespace D1
