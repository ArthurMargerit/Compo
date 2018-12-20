#include "Links/Fifo_out.hpp"


Fifo_out::Fifo_out()
{

}

Fifo_out::~Fifo_out()
{


}



void Fifo_out::set_from(Interface** pfrom)
{
  from = pfrom;
}





void Fifo_out::step()
{

}

void Fifo_out::connect()
{

  ofs.open(this->req);
  ifs.open(this->res);
  *(this->from) = this->build_f(ofs,ifs);
  this->f = (Fake*)*(this->from);
}

void Fifo_out::disconnect()
{

  ofs.close();
  ifs.close();
}
