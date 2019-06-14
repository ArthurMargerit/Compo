
#include "Deployments/D_t3/D_t3.hpp"

D_t3::D_t3() {}

D_t3::~D_t3() {}

void D_t3::init() {
  Deployment::init();

  this->components_add(&r2);

  this->components_add(&r3);

  this->components_add(&r4);

  this->components_add(&r5);
}

void D_t3::configuration() {
  Deployment::configuration();

  this->r2.configuration();

  this->r3.configuration();

  this->r4.configuration();

  this->r5.configuration();
}

void D_t3::link() {

  {

    s1.set_from_to((Interface **)&get_r2().get_i_r(), &get_c1p().get_i_p());

    s1.connect();
    this->link_add(&s1);
  }

  {

    s2.set_from_to((Interface **)&get_r3().get_i_r(), &get_c1p().get_i_p2());

    s2.connect();
    this->link_add(&s2);
  }

  {

    s3.set_from_to((Interface **)&get_r4().get_i_r(), &get_c1p().get_i_p2());

    s3.connect();
    this->link_add(&s3);
  }

  {

    s4.set_from_to((Interface **)&get_r5().get_i_r(), &get_c1p().get_i_p());

    s4.connect();
    this->link_add(&s4);
  }

  {

    li1.set_to(&get_r5().get_i_p1());

    li1.connect();
    this->link_add(&li1);
  }

  {

    li2.set_to(&get_r5().get_i_p2());

    li2.connect();
    this->link_add(&li2);
  }

  {

    lo1.set_from((Interface **)&get_r5().get_i_r1());
    lo1.set_build_f(get_build_fake(get_r5().get_i_r1()));

    lo1.connect();
    this->link_add(&lo1);
  }

  {

    lo2.set_from((Interface **)&get_r5().get_i_r2());
    lo2.set_build_f(get_build_fake(get_r5().get_i_r2()));

    lo2.connect();
    this->link_add(&lo2);
  }

  D_t2::link();

  this->r2.connection();

  this->r3.connection();

  this->r4.connection();

  this->r5.connection();
}

void D_t3::start() {
  D_t2::start();

  this->r2.start();

  this->r3.start();

  this->r4.start();

  this->r5.start();
}

void D_t3::stop() {
  D_t2::stop();

  this->r2.stop();

  this->r3.stop();

  this->r4.stop();

  this->r5.stop();
}

void D_t3::quit() { D_t2::quit(); }

C_t2r::C_t2r &D_t3::get_r2() { return this->r2; }

C_t2r::C_t2r &D_t3::get_r3() { return this->r3; }

C_t1r::C_t1r &D_t3::get_r4() { return this->r4; }

C_n::C_n &D_t3::get_r5() { return this->r5; }
