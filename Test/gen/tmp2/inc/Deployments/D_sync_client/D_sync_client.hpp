#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/C_r/C_r.hpp"

#include "Links/S_out_fifo/S_out_fifo.hpp"

class D_sync_client : public Deployment {
private:
  // COMPONENT

  C_r::C_r c1;

  // CONNECTOR

  // DATA

  // LINK

  S_out_fifo out;

public:
  D_sync_client();
  virtual ~D_sync_client();

  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;

  // GET //////////////////////////////////////////////////////////////////////
  // COMPONENT

  C_r::C_r &get_c1();

  // CONNECTOR

  // LINK

  S_out_fifo &get_out();

  void save(std::ostream &os) const;
  void load(std::istream &is);
};
