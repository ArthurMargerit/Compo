#include "Deployments/D1/D1.hpp"

// CONSTRUCTOR ////////////////////////////////////////////////////////////////
D1::D1() : Deployment() {}

D1::~D1() {}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void D1::init() {

  Deployment::init();

  this->components_add(&a);

  this->components_add(&b);

  this->components_add(&c);
}

void D1::configuration() {

  Deployment::configuration();

  this->a.configuration();

  this->b.configuration();

  this->c.configuration();
}

void D1::link() {

  Deployment::link();

  this->a.connection();

  this->b.connection();

  this->c.connection();
}

void D1::start() {
  Deployment::start();

  this->a.start();

  this->b.start();

  this->c.start();
}

void D1::stop() {
  Deployment::stop();

  this->a.stop();

  this->b.stop();

  this->c.stop();
}

void D1::quit() { Deployment::quit(); }
