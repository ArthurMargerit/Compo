#include "Deployments/HelloWord_server/HelloWord_server.hpp"

// CONSTRUCTOR ////////////////////////////////////////////////////////////////
HelloWord_server::HelloWord_server() : Deployment() {}

HelloWord_server::~HelloWord_server() {}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void HelloWord_server::init() {

  Deployment::init();

  this->link_add(&s1);

  this->components_add(&h1);
}

void HelloWord_server::configuration() {

  Deployment::configuration();

  this->s1.set_addr("127.0.0.1");

  this->s1.set_port(5555);

  this->s1.configuration();

  this->h1.configuration();
}

void HelloWord_server::link() {

  {

    // external link

    this->get_s1().set_in(

        &this->get_h1().get_inter());
  }

  Deployment::link();

  this->s1.connect();

  this->h1.connection();
}

void HelloWord_server::start() {
  Deployment::start();

  this->h1.start();
}

void HelloWord_server::stop() {
  Deployment::stop();

  this->h1.stop();
}

void HelloWord_server::quit() {
  Deployment::quit();

  this->s1.disconnect();
}
