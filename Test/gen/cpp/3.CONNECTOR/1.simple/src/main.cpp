#include "connectors/A.hpp"
#include "connectors/B.hpp"
#include "connectors/C.hpp"
#include "Components/C1/C1.hpp"
#include "Components/C2/C2.hpp"

int main() {

  {
    C1::C1 c;
    c.configuration();
    c.connection();
    c.start();

    std::ofstream ofs;
    ofs.open("c_math_p.sce");
    Logger_A a(c.get_p(), ofs);
    a.p.ping(1, 2);
    a.p.ping(3, 2);
    a.p.ping(5, 2);

    a.p.f1(0);
    a.p.f2();
    a.p.f3();

    a.p.get_a();
    a.p.get_b();
    a.p.set_a(1);
    a.p.set_b(2);
    a.p.get_a();
    a.p.get_b();
    c.stop();
    ofs.close();
  }

  std::cout << std::endl;
  {
    C1::C1 c1;
    C2::C2 c2;
    Async_B b;
    Logger_C c(c2.get_back_call(), std::cout);

    b.rr = &c.p;
    b.r = &c1.get_p();
    c2.set_call(&b.c);

    c1.configuration();
    c2.configuration();

    c1.connection();
    c2.connection();

    c1.start();
    c2.start();

    c1.step();
    c2.step();

    c1.stop();
    c2.stop();
  }
}
