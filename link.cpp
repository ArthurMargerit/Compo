#include "link.hpp"
#include "a.hpp"

void link_rec(a* l)
{
  a_rec* rec_2= new a_rec();
  rec_2->out = l;
  rec_2->wait_test();
}

void link_send(a** l)
{
  std::cout <<"SEND"  << "\n";

  *l = new a_send();
}

std::thread link(a* p, a** r)
{
  std::thread t_rec(link_rec, p);
  link_send(r);
  return t_rec;
}

