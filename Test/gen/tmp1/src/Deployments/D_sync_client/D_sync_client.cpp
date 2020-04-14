#include "Deployments/D_sync_client/D_sync_client.hpp"

// CONSTRUCTOR ////////////////////////////////////////////////////////////////
D_sync_client::D_sync_client() : Deployment() {}

D_sync_client::~D_sync_client() {}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void D_sync_client::init() {

  Deployment::init();

  this->link_add(&out);

  this->components_add(&c1);
}

void D_sync_client::configuration() {

  Deployment::configuration();

  this->out.configuration();

  this->c1.configuration();
}

void D_sync_client::link() {

  {

    // this->get_out().set_out(
    // this->get_c1().fake_io());

    this->get_out().connect();
    this->link_add(&this->get_out());
  }

  Deployment::link();

  this->c1.connection();
}

void D_sync_client::start() {
  Deployment::start();

  this->c1.start();
}

void D_sync_client::stop() {
  Deployment::stop();

  this->c1.stop();
}

void D_sync_client::quit() {
  Deployment::quit();

  this->out.disconnect();
}

// GET ////////////////////////////////////////////////////////////////////////
// COMPONENT

C_r::C_r &D_sync_client::get_c1() { return this->c1; }

// CONNECTOR

// LINK

S_out_fifo &D_sync_client::get_out() { return this->out; }
