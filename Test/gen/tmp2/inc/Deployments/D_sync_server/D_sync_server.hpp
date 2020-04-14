#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/C_p/C_p.hpp"

#include "Links/S_in_fifo/S_in_fifo.hpp"

class D_sync_server : public Deployment {
private:
  // COMPONENT

  C_p::C_p c1;

  // CONNECTOR

  // DATA

  // LINK

  S_in_fifo in;

public:
  D_sync_server();
  virtual ~D_sync_server();

  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;

  // GET //////////////////////////////////////////////////////////////////////
  // COMPONENT

  C_p::C_p &get_c1();

  // CONNECTOR

  // LINK

  S_in_fifo &get_in();

  void save(std::ostream &os) const;
  void load(std::istream &is);
};
