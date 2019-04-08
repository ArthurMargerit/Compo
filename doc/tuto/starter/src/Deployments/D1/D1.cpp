
#include "Deployments/D1/D1.hpp"

D1::D1() {}

D1::~D1() {}

void D1::init() {
  Deployment::init();

  this->components_add(&compo);
}

void D1::configuration() {
  Deployment::configuration();

  this->compo.configuration();
}

void D1::link() {

  Deployment::link();

  this->compo.connection();
}

void D1::start() {
  Deployment::start();

  this->compo.start();
}

void D1::stop() {
  Deployment::stop();

  this->compo.stop();
}

void D1::quit() {}
