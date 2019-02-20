#include "Links/Mem_zone/Mem_zone.hpp"


Mem_zone::Mem_zone()
{

}

Mem_zone::~Mem_zone()
{


}


void Mem_zone::set_to(Interface* pto)
{

}






void Mem_zone::step()
{

}

void Mem_zone::connect()
{

}

void Mem_zone::disconnect()
{

}

// Get and set /////////////////////////////////////////////////////////////

  string Mem_zone::get_file() const {
    return file;
   }

void Mem_zone::set_file(const string file) {
  this->file = file;
  }
