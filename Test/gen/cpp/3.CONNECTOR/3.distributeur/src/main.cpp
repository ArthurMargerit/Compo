#include "Components/C1/C1.hpp"
#include "connectors/Math_many_return_dist.hpp"
#include <iostream>
int main() {
  Math_many_return_dist d;
  C1::C1 c1, c2, c3, c4;


  c1.configuration();
  c2.configuration();
  c3.configuration();
  c4.configuration();


  c1.connection();
  c2.connection();
  c3.connection();
  c4.connection();

  c1.start();
  c2.start();
  c3.start();
  c4.start();

  c1.step();
  c2.step();
  c3.step();
  c4.step();

  d.list_r.push_back(&c1.get_p());
  d.list_r.push_back(&c2.get_p());
  d.list_r.push_back(&c3.get_p());
  d.list_r.push_back(&c4.get_p());

  d.c.set_a(1);
  d.c.set_b(10);

  {
    auto t = d.c.get_a();
    std::cout << "A: ";
    for (auto i_t : t) {
      std::cout << i_t << ", ";
    }
    std::cout << "\n";
  }

  {
    auto t = d.c.get_b();
    std::cout << "B: ";
    for (auto i_t : t) {
      std::cout << i_t << ", ";
    }
    std::cout << "\n";
  }

  {
    auto t = d.c.f1(1);
    std::cout << "f1: ";
    for (auto i_t : t) {
      std::cout << i_t << ", ";
    }
    std::cout << "\n";
  }

  {
    auto t = d.c.f2();
    std::cout << "f2: ";
    for (auto i_t : t) {
      std::cout << i_t << ", ";
    }
    std::cout << "\n";
  }

  d.c.f3();



  c1.stop();
  c2.stop();
  c3.stop();
  c4.stop();
}
