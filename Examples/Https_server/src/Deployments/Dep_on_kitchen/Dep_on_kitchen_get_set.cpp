#include "Deployments/Dep_on_kitchen/Dep_on_kitchen.hpp"

// GET ////////////////////////////////////////////////////////////////////////
// COMPONENT

Sensor &Dep_on_kitchen::get_s() { return this->s; }

// CONNECTOR

// LINK

CompoMe::Posix::Https_server_map_in &Dep_on_kitchen::get_l() { return this->l; }
