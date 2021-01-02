#include "Deployments/B/D1/D1.hpp"

namespace B {

// CONSTRUCTOR ////////////////////////////////////////////////////////////////
D1::D1() : Deployment() {}

D1::~D1() {}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void D1::init() { Deployment::init(); }

void D1::configuration() { Deployment::configuration(); }

void D1::link() { Deployment::link(); }

void D1::start() { Deployment::start(); }

void D1::stop() { Deployment::stop(); }

void D1::quit() { Deployment::quit(); }

} // namespace B
