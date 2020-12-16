#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/Sensor.hpp"

#include "Links/CompoMe/Posix/Https_server_map_in/Https_server_map_in.hpp"

class Dep_on_kitchen : public CompoMe::Deployment {
private:
  // COMPONENT

  Sensor s;

  // CONNECTOR

  // DATA

  // LINK

  CompoMe::Posix::Https_server_map_in l;

public:
  Dep_on_kitchen();
  virtual ~Dep_on_kitchen();

  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;

  // GET //////////////////////////////////////////////////////////////////////
  // COMPONENT

  Sensor &get_s();

  // CONNECTOR

  // LINK

  CompoMe::Posix::Https_server_map_in &get_l();
};
