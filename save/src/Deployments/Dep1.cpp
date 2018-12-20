
#include "Deployments/Dep1.hpp"


Dep1::Dep1() {
  
}

Dep1::~Dep1() {
  
}

void Dep1::init() {
  Deployment::init();

  
  this->components_add(&mp);
  
}

void Dep1::configuration() {
  Deployment::configuration();

  
  
  this->mp.configuration();
  
}

void Dep1::link() {
  {
    l1.set_req("/tmp/fifo1.req");
    l1.set_res("/tmp/fifo1.rep");
    l1.set_to(&mp.m);

    l1.connect();
    this->link_add(&l1);
  }


  Deployment::link();

  
  this->mp.connection();
  
}

void Dep1::start() {
  Deployment::start();

  
  this->mp.start();
  
}

void Dep1::stop() {
  Deployment::stop();

  
  this->mp.stop();
  
}

void Dep1::quit() {
  
}
