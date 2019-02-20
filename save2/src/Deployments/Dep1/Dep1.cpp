
#include "Deployments/Dep1/Dep1.hpp"


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
    
    
    
    lu.set_addr("127.0.0.1");
    
    lu.set_port(5454);
    
    
    
    lu.set_to(&mp.m);
    
    lu.connect();
    this->link_add(&lu);
    
    
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
