
#include "Deployments/Dep2.hpp"


Dep2::Dep2() {
  
}

Dep2::~Dep2() {
  
}

void Dep2::init() {
  Deployment::init();

  
  this->components_add(&m1);
  
  this->components_add(&m2);
  
  this->components_add(&mp);
  
}

void Dep2::configuration() {
  Deployment::configuration();

  
  
  this->m1.configuration();
  
  
  this->m2.configuration();
  
  
  this->mp.configuration();
  
}

void Dep2::link() {


  
  {
    
    
    
    l1.set_req("/tmp/fifo1.req");
    l1.set_res("/tmp/fifo1.rep");
    l1.build_f = build_fake(m1.compute_serv);
    
    l1.set_from((Interface**) &m1.compute_serv);
    
    l1.connect();
    this->link_add(&l1);
    
    

  }
  
  {
    

  }
  

  Deployment::link();

  
  this->m1.connection();
  
  this->m2.connection();
  
  this->mp.connection();
  
}

void Dep2::start() {
  Deployment::start();

  
  this->m1.start();
  
  this->m2.start();
  
  this->mp.start();
  
}

void Dep2::stop() {
  Deployment::stop();

  
  this->m1.stop();
  
  this->m2.stop();
  
  this->mp.stop();
  
}

void Dep2::quit() {
  
}
