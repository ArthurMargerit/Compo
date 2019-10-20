#include "Components/C1/C1.hpp"

#include "connectors/Math_logger.hpp"

int main() {
  C1::C1 c;
  c.configuration();
  c.connection();
  c.start();

  std::ofstream ofs;
  ofs.open("c_math_p.sce");
  Math_logger a(c.get_p(), ofs);

  // function call
  a.p.ping(1, 2);
  a.p.ping(3, 2);
  a.p.ping(5, 2);

  // function
  a.p.f1(0);
  a.p.f2();
  a.p.f3();

  // get set call
  a.p.set_a(1);
  a.p.set_b(2);
  a.p.get_a();
  a.p.get_b();

  c.stop();
  ofs.close();

}
