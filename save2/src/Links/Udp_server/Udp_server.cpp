#include "Links/Udp_server/Udp_server.hpp"


Udp_server::Udp_server()
{

}

Udp_server::~Udp_server()
{


}


void Udp_server::set_to(Interface* pto)
{

}






void Udp_server::step()
{

}

void Udp_server::connect()
{

}

void Udp_server::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////

  string Udp_server::get_addr() const {
    return addr;
   }

void Udp_server::set_addr(const string addr) {
  this->addr = addr;
  }
  uint Udp_server::get_port() const {
    return port;
   }

void Udp_server::set_port(const uint port) {
  this->port = port;
  }
