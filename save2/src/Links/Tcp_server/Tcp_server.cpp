#include "Links/Tcp_server/Tcp_server.hpp"


Tcp_server::Tcp_server()
{

}

Tcp_server::~Tcp_server()
{


}


void Tcp_server::set_to(Interface* pto)
{

}






void Tcp_server::step()
{

}

void Tcp_server::connect()
{

}

void Tcp_server::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////

  string Tcp_server::get_addr() const {
    return addr;
   }

void Tcp_server::set_addr(const string addr) {
  this->addr = addr;
  }
  uint Tcp_server::get_port() const {
    return port;
   }

void Tcp_server::set_port(const uint port) {
  this->port = port;
  }
