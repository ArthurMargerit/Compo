
#include "Deployments/D2/D2.hpp"

D2::D2() {}

D2::~D2() {}

void D2::init() {
  Deployment::init();

  this->components_add(&ca);

  this->components_add(&cb1);

  this->components_add(&cb2);

  this->components_add(&cb3);

  this->components_add(&cb4);
}

void D2::configuration() {
  Deployment::configuration();

  this->ca.configuration();

  this->cb1.configuration();

  this->cb2.configuration();

  this->cb3.configuration();

  this->cb4.configuration();
}

void D2::link() {

  {

    s1.set_from_to((Interface **)&cb1.a, &ca.a);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&cb2.a, &ca.a);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&cb3.a, &ca.b);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&cb4.a, &ca.b);

    s1.connect();
    this->link_add(&s1);
  }

  Deployment::link();

  this->ca.connection();

  this->cb1.connection();

  this->cb2.connection();

  this->cb3.connection();

  this->cb4.connection();
}

void D2::start() {
  Deployment::start();

  this->ca.start();

  this->cb1.start();

  this->cb2.start();

  this->cb3.start();

  this->cb4.start();
}

void D2::stop() {
  Deployment::stop();

  this->ca.stop();

  this->cb1.stop();

  this->cb2.stop();

  this->cb3.stop();

  this->cb4.stop();
}

void D2::quit() {}
