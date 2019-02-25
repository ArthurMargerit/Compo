#include "Links/Http_server/Http_server.hpp"


Http_server::Http_server()
{

}

Http_server::~Http_server()
{


}


void Http_server::set_to(Interface* pto)
{

}






void Http_server::step()
{

}

void Http_server::connect()
{

}

void Http_server::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////

  string Http_server::get_addr() const {
    return addr;
   }

void Http_server::set_addr(const string addr) {
  this->addr = addr;
  }
