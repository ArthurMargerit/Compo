#include "a.hpp"
#include "link.hpp"
#include <thread>


int main(int argc, char *argv[])
{

  a pro;

  std::string name_in = "fifo.send";
  std::string name_out = "fifo.rec";
  // req_1 -> pro_1

  Fifo_link_rec<a> link_rec_a(&pro, name_in, name_out);

  while(1){}
  
  return 0;
}
