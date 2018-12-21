
#include "Deployments/Dep3.hpp"


Dep3::Dep3() {
  
}

Dep3::~Dep3() {
  
}

void Dep3::init() {
  Deployment::init();

  
  this->components_add(&mp);
  
  this->components_add(&m1);
  
}

void Dep3::configuration() {
  Deployment::configuration();

  
  
  this->mp.configuration();
  
  
  this->m1.configuration();
  
}

void Dep3::link() {


  
  {
    
    
    
    s1.set_from_to((Interface**)&m1.compute_serv, &mp.m);
    
    s1.connect();
    this->link_add(&s1);
    
    

  }
  

  Deployment::link();

  
  this->mp.connection();
  
  this->m1.connection();
  
}

void Dep3::start() {
  Deployment::start();

  
  this->mp.start();
  
  this->m1.start();
  
}

void Dep3::stop() {
  Deployment::stop();

  
  this->mp.stop();
  
  this->m1.stop();
  
}

void Dep3::quit() {
  
}
