
#include "Deployments/D_t2/D_t2.hpp"

D_t2::D_t2() {}

D_t2::~D_t2() {}

void D_t2::init() { Deployment::init(); }

void D_t2::configuration() { Deployment::configuration(); }

void D_t2::link() {

  {

    s0.set_from_to((Interface **)&get_c1r().get_i_r(), &get_c1p().get_i_p());

    s0.connect();
    this->link_add(&s0);
  }

  D_t1::link();
}

void D_t2::start() { D_t1::start(); }

void D_t2::stop() { D_t1::stop(); }

void D_t2::quit() { D_t1::quit(); }
