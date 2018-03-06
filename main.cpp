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
  req->test();
}



void test_fifo_rec(a** req, std::string name_in, std::string name_out)
{
  Fifo_link_send<a,a_send> link_send_a(req, name_in, name_out);
}

void test_fifo(){
  a pro;
  a *req;
  req = NULL;

  std::string name_in = "fifo.send";
  std::string name_out = "fifo.rec";
  // req_1 -> pro_1
  auto t = std::thread(test_fifo_rec, &req, name_in, name_out);
  Fifo_link_rec<a> link_rec_a(&pro, name_in, name_out);
  req->test();

  t.join();
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
