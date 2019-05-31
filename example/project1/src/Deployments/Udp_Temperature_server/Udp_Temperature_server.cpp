
#include "Deployments/Udp_Temperature_server/Udp_Temperature_server.hpp"

Udp_Temperature_server::Udp_Temperature_server() {}

Udp_Temperature_server::~Udp_Temperature_server() {}

void Udp_Temperature_server::init() {
  Deployment::init();

  this->components_add(&server);
}

void Udp_Temperature_server::configuration() {
  Deployment::configuration();

  this->server.configuration();
}

void Udp_Temperature_server::link() {

  {

    in.set_to(&server.reporter);

    in.connect();
    this->link_add(&in);
  }

  Deployment::link();

  this->server.connection();
}

void Udp_Temperature_server::start() {
  Deployment::start();

  this->server.start();
}

void Udp_Temperature_server::stop() {
  Deployment::stop();

  this->server.stop();
}

void Udp_Temperature_server::quit() {}
