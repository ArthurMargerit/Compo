
#include "Deployments/D_t1/D_t1.hpp"

D_t1::D_t1() {}

D_t1::~D_t1() {}

void D_t1::init() {
  Deployment::init();

  this->components_add(&c1r);

  this->components_add(&c1p);
}

void D_t1::configuration() {
  Deployment::configuration();

  this->c1r.configuration();

  this->c1p.configuration();
}

void D_t1::link() {

  Deployment::link();

  this->c1r.connection();

  this->c1p.connection();
}

void D_t1::start() {
  Deployment::start();

  this->c1r.start();

  this->c1p.start();
}

void D_t1::stop() {
  Deployment::stop();

  this->c1r.stop();

  this->c1p.stop();
}

void D_t1::quit() { Deployment::quit(); }

C_t2r::C_t2r &D_t1::get_c1r() { return this->c1r; }

C_t2p::C_t2p &D_t1::get_c1p() { return this->c1p; }
