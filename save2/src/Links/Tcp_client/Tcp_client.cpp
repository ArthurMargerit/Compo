#include "Links/Tcp_client/Tcp_client.hpp"


Tcp_client::Tcp_client()
{

}

Tcp_client::~Tcp_client()
{


}



void Tcp_client::set_from(Interface** pfrom)
{

}





void Tcp_client::step()
{

}

void Tcp_client::connect()
{

}

void Tcp_client::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////

  string Tcp_client::get_addr() const {
    return addr;
   }

void Tcp_client::set_addr(const string addr) {
  this->addr = addr;
  }
  uint Tcp_client::get_port() const {
    return port;
   }

void Tcp_client::set_port(const uint port) {
  this->port = port;
  }
