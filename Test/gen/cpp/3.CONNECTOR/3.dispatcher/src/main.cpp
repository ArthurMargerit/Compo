#include <iostream>
#include "Components/C1.hpp"
#include "connectors/Math_dispatcher.hpp"
#include "connectors/A/M_d.hpp"
#include "connectors/A/B/M_d.hpp"
#include "connectors/B/A/M_d.hpp"
#include "catch.hpp"

TEST_CASE("Connector dispatcher", "[Connector][dispatcher]") {

  C1 c1,c2,c3;

  c1.configuration();
  c2.configuration();
  c3.configuration();

  c1.connection();
  c2.connection();
  c3.connection();

  c1.start();
  c2.start();
  c3.start();

  Math_dispatcher md;
  md.list_r.push_back(&c1.get_p());
  md.list_r.push_back(&c2.get_p());
  md.list_r.push_back(&c3.get_p());

  md.c.set_a(1);
  md.c.set_a(2);
  md.c.set_a(3);
  md.c.set_a(4);
  md.c.set_a(5);
  md.c.set_a(6);

  std::cout << md.c.get_a()  << "\n";
  std::cout << md.c.get_a() << "\n";
  std::cout << md.c.get_a() << "\n";
  std::cout << md.c.get_a() << "\n";
  std::cout << md.c.get_a() << "\n";
  std::cout << md.c.get_a() << "\n";

  md.c.set_a(1);
  md.c.set_a(2);
  md.c.set_a(3);

  md.c.set_a(4);
  md.c.set_a(5);
  md.c.set_a(6);

  std::cout << md.c.f1(1)  << "\n";
  std::cout << md.c.f1(1) << "\n";
  std::cout << md.c.f1(1) << "\n";

  std::cout << md.c.f2() << "\n";
  std::cout << md.c.f2() << "\n";
  std::cout << md.c.f2() << "\n";

  md.c.f3();
  md.c.f3();
  md.c.f3();

  c1.stop();
  c2.stop();
  c3.stop();

  A::M_d md1;
  A::B::M_d md2;
  B::A::M_d md3;
}
