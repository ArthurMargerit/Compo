#include "Deployments/Deployment.hpp"
#include <iostream>
namespace CompoMe {

Deployment::Deployment() {}

Deployment::~Deployment() {}

void Deployment::link_list() const {
  for (Link *l : this->links) {
  }
}

void Deployment::link_add(Link *l) { this->links.push_back(l); }

void Deployment::components_list() const {}

void Deployment::components_add(Component *l) { this->components.push_back(l); }

void Deployment::init() {}

void Deployment::step() {
  for (Link *l : this->links) {
    l->step();
  }

  for (Component *c : this->components) {
    c->step();
  }
}

void Deployment::configuration() {}

void Deployment::link() {}

void Deployment::start() {}

void Deployment::stop() {}

void Deployment::quit() {}

} // namespace CompoMe