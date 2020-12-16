#include "Deployments/Dep_on_kitchen/Dep_on_kitchen.hpp"

// CONSTRUCTOR ////////////////////////////////////////////////////////////////
Dep_on_kitchen::Dep_on_kitchen() : Deployment() {}

Dep_on_kitchen::~Dep_on_kitchen() {}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void Dep_on_kitchen::init() {

  Deployment::init();

  this->link_add(&l);

  this->components_add(&s);
}

void Dep_on_kitchen::configuration() {

  Deployment::configuration();

  this->l.set_addr("127.0.0.1");

  this->l.set_port(8081);

  this->l.configuration();

  this->s.configuration();
}

void Dep_on_kitchen::link() {

  {

    // external link

    this->get_l().set_in("/info", &this->get_s().get_information());
  }

  {

    // external link

    this->get_l().set_in("/cap", &this->get_s().get_capteur1());
  }

  Deployment::link();

  this->l.connect();

  this->s.connection();
}

void Dep_on_kitchen::start() {
  Deployment::start();

  this->s.start();
}

void Dep_on_kitchen::stop() {
  Deployment::stop();

  this->s.stop();
}

void Dep_on_kitchen::quit() {
  Deployment::quit();

  this->l.disconnect();
}
