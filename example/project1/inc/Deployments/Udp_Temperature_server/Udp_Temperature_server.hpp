#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/Temperature_Server/Temperature_Server.hpp"

#include "Links//.hpp"

class Udp_Temperature_server : public Deployment {
private:
  Temperature_Server::Temperature_Server server;

  in;

public:
  Udp_Temperature_server();
  virtual ~Udp_Temperature_server();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};