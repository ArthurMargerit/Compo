
#include "Interfaces/Interface_test/Interface_test.hpp"
#include "Links/Udp_client/Udp_client.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Interface_test *it;

  Udp_client ctl = Udp_client();
  ctl.set_addr("127.0.0.1");
  ctl.set_port(61010);
  Interface * ite = it;
  ctl.set_from(&ite);

  ctl.connect();
  ctl.step();
  ctl.disconnect();
  return 0;
}
