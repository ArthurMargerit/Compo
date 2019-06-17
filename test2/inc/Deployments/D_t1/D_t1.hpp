#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/C_t2r/C_t2r.hpp"

#include "Components/C_t2p/C_t2p.hpp"

class D_t1 : public Deployment {
private:
  C_t2r::C_t2r c1r;

  C_t2p::C_t2p c1p;

public:
  D_t1();
  virtual ~D_t1();

  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;

  C_t2r::C_t2r &get_c1r();

  C_t2p::C_t2p &get_c1p();
};