#include "a.hpp"

#include "link.hpp"
#include <thread>


int main(int argc, char *argv[])
{
  a *req;
  req = NULL;

  std::string name_in = "fifo.send";
  std::string name_out = "fifo.rec";

  Fifo_link_send<a,a_send> link_send_a(&req, name_in, name_out);

  req->test(1,1);
  req->test(2,2);
  req->test(3,3);
  req->test(4,4);
  req->test(0,0);

  return 0;
}

