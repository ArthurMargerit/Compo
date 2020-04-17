#include "catch.hpp"

#include "Data/Struct_Base1.hpp"
#include "Data/Struct_Base1_rev.hpp"
#include "Data/Struct_Node.hpp"
#include "Data/Struct_Node2.hpp"
#include "Data/code.hpp"

#include <memory>
#include <sstream>

TEST_CASE("Struct complex", "[Struct][complex]"){
  init_code();

  { // b1
    Base1 b1;
    b1.a_ea().set_pa(99);
    b1.a_ea().set_pb(99);
    std::cout << b1 << std::endl;

    b1.set_ep(&b1.a_ea());
    std::cout << b1 << std::endl;

    Elem e;
    b1.set_ep(&e);
    std::cout << b1 << "\n";
  }

  {
    // b1
    Base1_rev b1;
    b1.a_ea().set_pa(99);
    b1.a_ea().set_pb(99);
    std::cout << b1 << std::endl;

    b1.set_ep(&b1.a_ea());
    std::cout << b1 << std::endl;

    Elem e;
    b1.set_ep(&e);
    std::cout << b1 << "\n";
  }

  {
    // a* - a
    pNode pa;
    Node a;
    pa = &a;
    std::cout << a << "\n";
    std::cout << pa << "\n";
    std::cout << &pa << "\n";
  }

  {
    //       - b -
    // a - <       > - d
    //       - c -
    Node a, b, c, d;
    a.set_g(&b);
    a.set_d(&c);
    b.set_d(&d);
    c.set_g(&d);
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";

    std::cout << &a << "\n";
    std::cout << &b << "\n";
    std::cout << &c << "\n";
    std::cout << &d << "\n";

    Node n;
    std::stringstream ss;
    ss << a;
    ss >> n;

    std::cout << "____"
              << "\n";
    std::cout << a << "\n";
    std::cout << " == "
              << "\n";
    std::cout << n << "\n";
    std::cout << "____"
              << "\n";

    if (n.a_d() == NULL) {
      std::cerr << "Error 1";
      throw "Error 1";
    }

    if (n.a_g() == NULL) {
      std::cerr << "Error 2";
      throw "Error 2";
    }

    if (n.a_g()->a_d() != n.a_d()->a_g()) {
      std::cerr << "Error 3";
      throw "Error 3";
    }
  }

  {
    Node a, b, c, d;
    Node a1, b1, c1, d1;

    a.a_g() = &b;
    b.a_g() = &c;
    c.a_g() = &d;
    d.a_g() = &a;

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";

    std::stringstream ss;
    ss << a << b << c << d;
    ss >> a1 >> b1 >> c1 >> d1;
  }

  {
    psNode ps;
    if (ps != nullptr) {
      std::cerr << "Erreur 4";
      throw "erreur 5";
    }

    for (int i = 0; i < 100; ++i) {
      ps = std::make_shared<Node2>();
    }

    ps = nullptr;
  }

  // node point to the same
  {
    Node2 n2a;
    Node2 n2b;
    n2a.g = std::make_shared<Node2>();
    n2a.d = std::make_shared<Node2>();
    auto n = std::make_shared<Node2>();
    n2a.g->g = n;
    n2a.g->d = n;
    n2a.d->g = n;
    n2a.d->d = n;

    std::cout << n2a << "\n";
    std::cout << n2b << "\n";

    std::stringstream ss;
    ss << n2a;
    ss >> n2b;

    std::cout << n2a << "\n";
    std::cout << n2b << "\n";
  }

  // circular one
  {
    auto n2a1 = std::make_shared<Node2>();
    auto n2a2 = std::make_shared<Node2>();
    auto n2a3 = std::make_shared<Node2>();
    auto n2a4 = std::make_shared<Node2>();
    auto n2a5 = std::make_shared<Node2>();

    n2a1->g = n2a2;
    n2a2->g = n2a3;
    n2a3->g = n2a4;
    n2a4->g = n2a5;
    n2a5->g = n2a1;
    std::shared_ptr<Node2> b;
    std::stringstream ss;
    ss << n2a1;
    ss >> b;

    std::cout << n2a1 << "\n";
    std::cout << b << "\n";

    if (n2a1->g->g->g->g->g != n2a1) {
      throw "not circular";
    }
  }
}
