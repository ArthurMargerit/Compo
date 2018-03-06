#include "a.hpp"
#include "link.hpp"
#include <thread>

void test_direct(){
  a pro;
  a *req;
  req = NULL;

  // req_1 -> pro_1
  auto link_1 = Direct_link<a>(pro, req);
  std::cout << req << "\n";
  req->test(1,2);
}


void test_fifo(){
  a pro;

  std::string name_in = "fifo.send";
  std::string name_out = "fifo.rec";
  // req_1 -> pro_1

  Fifo_link_rec<a> link_rec_a(&pro, name_in, name_out);

}



int main(int argc, char *argv[])
{
  test_direct();
  test_fifo();

  // a * req_2;
  // req_2 = NULL;
  // a pro_2;
  // auto link_2 = Fifo_link<a>(pro_2,req_2);

  // req_2->test();
  // req_2->test();
  // req_2->test();
  // req_2->test();

  // link_2.stop();

  // a * req_3;
  // req_3 = NULL;

  // a pro_3;
  // auto link_3 = Fifo_link<a>(&pro_3, &req_3);

  // req_3->test();
  // req_3->test();
  // req_3->test();
  // req_3->test();

  // a.join();

  return 0;
}
