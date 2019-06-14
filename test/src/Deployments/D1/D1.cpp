
#include "Deployments/D1/D1.hpp"

D1::D1() {}

D1::~D1() {}

void D1::init() {
  Deployment::init();

  this->components_add(&ca);

  this->components_add(&cb);

  this->components_add(&cc);
}

void D1::configuration() {
  Deployment::configuration();

  this->ca.configuration();

  this->cb.configuration();

  this->cc.configuration();
}

void D1::link() {

  {

    s1.set_from_to((Interface **)&cc.d, &cb.b);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&ca.c, &cb.a);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&ca.d, &cb.b);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&cc.c, &ca.a);

    s1.connect();
    this->link_add(&s1);
  }

  Deployment::link();

  this->ca.connection();

  this->cb.connection();

  this->cc.connection();
}

void D1::start() {
  Deployment::start();

  this->ca.start();

  this->cb.start();

  this->cc.start();
}

void D1::stop() {
  Deployment::stop();

  this->ca.stop();

  this->cb.stop();

  this->cc.stop();
}

void D1::quit() {}
