#include "Links/Mem_client/Mem_client.hpp"


Mem_client::Mem_client()
{

}

Mem_client::~Mem_client()
{


}



void Mem_client::set_from(Interface** pfrom)
{

}





void Mem_client::step()
{

}

void Mem_client::connect()
{

}

void Mem_client::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////

  string Mem_client::get_file() const {
    return file;
   }

void Mem_client::set_file(const string file) {
  this->file = file;
  }
