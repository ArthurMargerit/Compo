#include "connectors/A.hpp"
#include "Components/C1/C1.hpp"


int main() {

  C1::C1 c;
  c.configuration();
  c.connection();
  c.start();

  std::ofstream ofs;
  ofs.open("c_math_p.sce");
  Logger_A a(c.get_p(),ofs);
  a.p.ping(1,2);
  a.p.ping(3,2);
  a.p.ping(5,2);
  a.p.get_a();
  a.p.get_b();
  a.p.set_a(1);
  a.p.set_b(2);
  a.p.get_a();
  a.p.get_b();
  c.stop();
  ofs.close();
}
