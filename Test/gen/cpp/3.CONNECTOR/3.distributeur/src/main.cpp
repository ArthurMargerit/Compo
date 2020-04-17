#include "Components/C1/C1.hpp"
// basic
#include "connectors/Math_by_id_dist.hpp"
#include "connectors/Math_many_dist.hpp"
#include "connectors/Math_many_return_dist.hpp"

// all
#include "connectors/Math_all_dist.hpp"

// complex
#include "connectors/Math_many_return_by_id_dist.hpp"

// namespace
// basic
#include "connectors/I/M_by_id_dist.hpp"
#include "connectors/I/M_many_dist.hpp"
#include "connectors/I/M_many_return_dist.hpp"

// all
#include "connectors/I/M_all_dist.hpp"

#include <iostream>
#include "catch.hpp"
#include "Data/code.hpp"

TEST_CASE("Connector logger", "[Connector][logger]") {

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
  {
    ////////////////////////////////////////// TO MANY RETURN
    Math_many_return_dist d;
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
  }
  {
    ////////////////////////////////////////// TO MANY
    Math_many_dist d2;
    d2.list_r.push_back(&c1.get_p());
    d2.list_r.push_back(&c2.get_p());
    d2.list_r.push_back(&c3.get_p());
    d2.list_r.push_back(&c4.get_p());
    // One module
    d2.c.set_a({1});
    d2.c.set_b({11});

    // Two modulo
    d2.c.set_a({1, 2});
    d2.c.set_b({11, 12});

    // Full modulo
    d2.c.set_a({1, 2, 3, 4});
    d2.c.set_b({11, 12, 13, 14});

    {
      auto t = d2.c.get_a();
      std::cout << "a: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.get_b();
      std::cout << "b: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.f1({20, 21, 22, 23});
      std::cout << "f1: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.f2();
      std::cout << "f2: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.ping({1, 2, 3, 4}, {1});
      std::cout << "ping: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.ping({1, 2, 3, 4}, {1, 2});
      std::cout << "ping: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.ping({1, 2, 3, 4}, {1, 2, 3});
      std::cout << "ping: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.ping({1, 2, 3, 4}, {1, 2, 3, 4});
      std::cout << "ping: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.ping({1, 2, 3}, {1, 2, 3, 4});
      std::cout << "ping: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.ping({1, 2}, {1, 2, 3, 4});
      std::cout << "ping: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d2.c.ping({1}, {1, 2, 3, 4});
      std::cout << "ping: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }
    d2.c.f3();
  }

  {
    ////////////////////////////////////////// BY ID
    Math_by_id_dist d3;
    d3.list_r.push_back(&c1.get_p());
    d3.list_r.push_back(&c2.get_p());
    d3.list_r.push_back(&c3.get_p());
    d3.list_r.push_back(&c4.get_p());

    d3.c.ping(0, 2, 3);
    d3.c.ping(1, 2, 3);
    d3.c.ping(2, 2, 3);
    d3.c.ping(3, 2, 3);

    d3.c.f1(0, 10);
    d3.c.f1(1, 20);
    d3.c.f1(2, 30);
    d3.c.f1(3, 40);

    d3.c.f2(0);
    d3.c.f2(1);
    d3.c.f2(2);
    d3.c.f2(3);

    d3.c.set_a(0, 1);
    d3.c.set_a(1, 2);
    d3.c.set_a(2, 3);
    d3.c.set_a(3, 4);

    d3.c.get_a(0);
    d3.c.get_a(1);
    d3.c.get_a(2);
    d3.c.get_a(3);

    d3.c.set_b(0, 11);
    d3.c.set_b(1, 12);
    d3.c.set_b(2, 13);
    d3.c.set_b(3, 14);

    d3.c.get_b(0);
    d3.c.get_b(1);
    d3.c.get_b(2);
    d3.c.get_b(3);
  }

  {
    Math_all_dist d;
    d.list_r.push_back(&c1.get_p());
    d.list_r.push_back(&c2.get_p());
    d.list_r.push_back(&c3.get_p());
    d.list_r.push_back(&c4.get_p());

    // all but c1 with 1 , c2 with 2, c3 wiht 3 etc 
    d.cm.set_a({1,2,3,4});

    // all with 1
    d.cmr.set_a(1);

    // C1 with 1
    d.cwi.set_a(0,1);
  }

  {
    ////////////////////////////////////////// COMPLEX
    Math_many_return_dist dmr1, dmr2, dmr3, dmr4;
    Math_many_return_by_id_dist d;
    d.list_r.push_back(&dmr1.c);
    d.list_r.push_back(&dmr2.c);
    d.list_r.push_back(&dmr3.c);
    d.list_r.push_back(&dmr4.c);

    // group 1
    dmr1.list_r.push_back(&c1.get_p());
    dmr1.list_r.push_back(&c2.get_p());

    // group 2
    dmr2.list_r.push_back(&c1.get_p());
    dmr2.list_r.push_back(&c3.get_p());
    dmr2.list_r.push_back(&c4.get_p());

    // group 3
    dmr3.list_r.push_back(&c4.get_p());

    // full group
    dmr4.list_r.push_back(&c1.get_p());
    dmr4.list_r.push_back(&c2.get_p());
    dmr4.list_r.push_back(&c3.get_p());
    dmr4.list_r.push_back(&c4.get_p());

    d.c.set_a(0, 0); // group 1 - value
    {
      auto t = d.c.get_a(0);
      std::cout << "a: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    d.c.set_a(1, 1); // group 2 - value
    {
      auto t = d.c.get_a(1);
      std::cout << "a: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    d.c.set_a(2, 2); // group 3 - value
    {
      auto t = d.c.get_a(2);
      std::cout << "a: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }

    {
      auto t = d.c.get_a(3);
      std::cout << "a: ";
      for (auto i_t : t) {
        std::cout << i_t << ", ";
      }
      std::cout << "\n";
    }
  }

  c1.stop();
  c2.stop();
  c3.stop();
  c4.stop();
}
