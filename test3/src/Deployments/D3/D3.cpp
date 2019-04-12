
#include "Deployments/D3/D3.hpp"

D3::D3() {}

D3::~D3() {}

void D3::init() {
  Deployment::init();

  this->components_add(&ca);

  this->components_add(&cb);

  this->components_add(&ca2);

  this->components_add(&cb2);

  this->components_add(&cc);

  this->components_add(&cc2);

  this->components_add(&cc4);

  this->components_add(&cc3);
}

void D3::configuration() {
  Deployment::configuration();

  this->ca.configuration();

  this->cb.configuration();

  this->ca2.configuration();

  this->cb2.configuration();

  this->cc.set_v3(6);

  this->cc.set_v2(6);

  this->cc.set_v1(6);

  this->cc.configuration();

  this->cc2.configuration();

  this->cc4.set_v2(6);

  this->cc4.configuration();

  this->cc3.set_v3(6);

  this->cc3.configuration();
}

void D3::link() {

  {

    s2.set_name("lapin");

    s2.set_to(&cb2.a);

    s2.connect();
    this->link_add(&s2);
  }

  {

    s3.set_from((Interface **)&ca2.a);

    s3.connect();
    this->link_add(&s3);
  }

  {

    s4.set_to(&cc2.a);

    s4.connect();
    this->link_add(&s4);
  }

  {

    s5.set_from((Interface **)&cc4.b);

    s5.connect();
    this->link_add(&s5);
  }

  {

    s1.set_from_to((Interface **)&cc2.b, &cc3.a);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&cc3.b, &cc4.a);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&ca.a, &cc.a);

    s1.connect();
    this->link_add(&s1);
  }

  {

    s1.set_from_to((Interface **)&cc.b, &cb.a);

    s1.connect();
    this->link_add(&s1);
  }

  Deployment::link();

  this->ca.connection();

  this->cb.connection();

  this->ca2.connection();

  this->cb2.connection();

  this->cc.connection();

  this->cc2.connection();

  this->cc4.connection();

  this->cc3.connection();
}

void D3::start() {
  Deployment::start();

  this->ca.start();

  this->cb.start();

  this->ca2.start();

  this->cb2.start();

  this->cc.start();

  this->cc2.start();

  this->cc4.start();

  this->cc3.start();
}

void D3::stop() {
  Deployment::stop();

  this->ca.stop();

  this->cb.stop();

  this->ca2.stop();

  this->cb2.stop();

  this->cc.stop();

  this->cc2.stop();

  this->cc4.stop();

  this->cc3.stop();
}

void D3::quit() {}
