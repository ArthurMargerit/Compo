#include "Links/Http_client/Http_client.hpp"


Http_client::Http_client()
{

}

Http_client::~Http_client()
{


}



void Http_client::set_from(Interface** pfrom)
{

}





void Http_client::step()
{

}

void Http_client::connect()
{

}

void Http_client::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////

  string Http_client::get_addr() const {
    return addr;
   }

void Http_client::set_addr(const string addr) {
  this->addr = addr;
  }
