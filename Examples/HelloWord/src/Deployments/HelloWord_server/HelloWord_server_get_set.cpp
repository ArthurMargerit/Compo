#include "Deployments/HelloWord_server/HelloWord_server.hpp"

// GET ////////////////////////////////////////////////////////////////////////
// COMPONENT

HelloWord &HelloWord_server::get_h1() { return this->h1; }

// CONNECTOR

// LINK

CompoMe::Posix::Udp_server_in &HelloWord_server::get_s1() { return this->s1; }
