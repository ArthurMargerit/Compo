#include "Deployments/D1/A/A.hpp"

namespace D1 {

// CONSTRUCTOR ////////////////////////////////////////////////////////////////
A::A() : Deployment() {}

A::~A() {}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void A::init() { Deployment::init(); }

void A::configuration() { Deployment::configuration(); }

void A::link() { Deployment::link(); }

void A::start() { Deployment::start(); }

void A::stop() { Deployment::stop(); }

void A::quit() { Deployment::quit(); }

} // namespace D1
