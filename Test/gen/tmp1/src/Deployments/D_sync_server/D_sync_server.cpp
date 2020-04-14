#include "Deployments/D_sync_server/D_sync_server.hpp"

// CONSTRUCTOR ////////////////////////////////////////////////////////////////
D_sync_server::D_sync_server() : Deployment() {}

D_sync_server::~D_sync_server() {}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void D_sync_server::init() {

  Deployment::init();

  this->link_add(&in);

  this->components_add(&c1);
}

void D_sync_server::configuration() {

  Deployment::configuration();

  this->in.configuration();

  this->c1.configuration();
}

void D_sync_server::link() {

  {

    this->get_in().set_in(&this->get_c1().get_ii());

    this->get_in().connect();
    this->link_add(&this->get_in());
  }

  Deployment::link();

  this->c1.connection();
}

void D_sync_server::start() {
  Deployment::start();

  this->c1.start();
}

void D_sync_server::stop() {
  Deployment::stop();

  this->c1.stop();
}

void D_sync_server::quit() {
  Deployment::quit();

  this->in.disconnect();
}

// GET ////////////////////////////////////////////////////////////////////////
// COMPONENT

C_p::C_p &D_sync_server::get_c1() { return this->c1; }

// CONNECTOR

// LINK

S_in_fifo &D_sync_server::get_in() { return this->in; }
