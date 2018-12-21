#include "Links/Fifo_in.hpp"


Fifo_in::Fifo_in()
{

}

Fifo_in::~Fifo_in()
{


}


void Fifo_in::set_to(Interface* pto)
{
  this->to = pto;
}




void Fifo_in::step()
{
  this->mutex_in.unlock();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));;
  this->mutex_in.lock();

}

void Fifo_in::connect()
{
  ifs.open(this->req);
  ofs.open(this->res);
  this->c = this->to->get_caller();

  auto  f = [this]()
            {
              while(ifs){
                mutex_in.unlock();
                c->call(ifs,ofs);
                mutex_in.lock();
              }
            };

  this->t= std::thread(f);
}

void Fifo_in::disconnect()
{

  ifs.close();
  ofs.close();
  this->t.join();
}
