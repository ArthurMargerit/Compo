
#include "Deployments/Dep2/Dep2.hpp"

Dep2::Dep2() {}

Dep2::~Dep2() {}

void Dep2::init() {
  Deployment::init();

  this->components_add(&mc);
}

void Dep2::configuration() {
  Deployment::configuration();

  this->mc.configuration();
}

void Dep2::link() {

  {

    l.set_addr("127.0.0.1");

    l.set_port(5454);

    l.set_from((Interface **)&mc.compute_serv);

    l.connect();
    this->link_add(&l);
  }

  Deployment::link();

  this->mc.connection();
}

void Dep2::start() {
  Deployment::start();

  this->mc.start();
}

void Dep2::stop() {
  Deployment::stop();

  this->mc.stop();
}

void Dep2::quit() {}
