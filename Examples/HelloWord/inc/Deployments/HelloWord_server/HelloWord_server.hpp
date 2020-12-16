#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/HelloWord.hpp"

#include "Links/CompoMe/Posix/Udp_server_in/Udp_server_in.hpp"

class HelloWord_server : public CompoMe::Deployment {
private:
  // COMPONENT

  HelloWord h1;

  // CONNECTOR

  // DATA

  // LINK

  CompoMe::Posix::Udp_server_in s1;

public:
  HelloWord_server();
  virtual ~HelloWord_server();

  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;

  // GET //////////////////////////////////////////////////////////////////////
  // COMPONENT

  HelloWord &get_h1();

  // CONNECTOR

  // LINK

  CompoMe::Posix::Udp_server_in &get_s1();
};
