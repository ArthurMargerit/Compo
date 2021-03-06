#include "catch.hpp"

#include "Structs/Base1.hpp"
#include "Structs/Base1_rev.hpp"
#include "Structs/Node.hpp"
#include "Structs/Node2.hpp"

#include "Data/code.hpp"

#include <memory>
#include <sstream>

TEST_CASE("Struct complex basic pointer", "[Struct][complex][Pointer]") {
  init_code();

  Base1 b1, b2;
  b1.a_ea().set_pa(99);
  b1.a_ea().set_pb(99);

  std::stringstream ss1;
  ss1 << b1;
  REQUIRE(ss1.str().find("ep:*(0)") != std::string::npos); // found
  ss1.str("");

  b1.set_ep(&b1.a_ea());
  ss1 << b1;
  REQUIRE(ss1.str().find("ep:*(0)") == std::string::npos); // not found

  std::stringstream ss;
  ss << b1;
  INFO(ss.str());
  ss >> b2;

  REQUIRE(b2.a_ea().get_pa() == 99);
  REQUIRE(b2.a_ea().get_pb() == 99);
  REQUIRE(b2.a_ep()->get_pa() == 99);
  REQUIRE(b2.a_ep()->get_pb() == 99);
  REQUIRE(&b2.a_ea() == b2.get_ep());
  REQUIRE(&b2.a_ep() != &b1.a_ep());

  Elem e;
  e.set_pa(1);
  e.set_pb(2);
  b1.set_ep(&e);

  ss << b1;
  ss >> b2;

  REQUIRE(b2.a_ea().get_pa() == 99);
  REQUIRE(b2.a_ea().get_pb() == 99);
  REQUIRE(b2.a_ep()->get_pa() == 1);
  REQUIRE(b2.a_ep()->get_pb() == 2);
}

TEST_CASE("Struct complex nullptr pointer",
          "[Struct][complex][Pointer][Null]") {
  Elem *pe = nullptr;
  Base1 *pb = nullptr;
  CompoMe::Struct *ps = nullptr;

  std::stringstream ss;

  ss << pe;
  REQUIRE(ss.str() == "*(0)");
  ss.str("");

  ss << pb;
  REQUIRE(ss.str() == "*(0)");
  ss.str("");

  ss << ps;
  REQUIRE(ss.str() == "*(0)");
}

TEST_CASE("Struct complex diamond pointer",
          "[Struct][complex][Pointer][Diamond]") {

  //            /--null
  //       /-b-<     /--null
  //    a-<     >-d-<
  //       L-c-<     L--null
  //            L--null

  Node a, b, c, d;
  a.set_g(&b);
  a.set_d(&c);
  b.set_d(&d);
  c.set_g(&d);
  std::stringstream ss;
  Node a_i;

  ss << a;
  ss >> a_i;
  INFO("a = " << a);
  REQUIRE(a_i.get_g() != NULL);
  REQUIRE(a_i.get_d() != NULL);
  REQUIRE(a_i.a_g()->get_g() == NULL);
  REQUIRE(a_i.a_d()->get_d() == NULL);

  REQUIRE(a_i.a_g()->get_d() == a_i.a_d()->get_g());
}

TEST_CASE("Struct complex circular pointer",
          "[Struct][complex][Pointer][Circular]") {
  Node a, b, c, d;
  Node a_i;

  // a -> b -> c -> d -+
  //  L---<----<---<---/
  a.a_g() = &b;
  b.a_g() = &c;
  c.a_g() = &d;
  d.a_g() = &a;

  std::stringstream ss;
  ss << a;
  ss >> a_i;

  INFO("a = " << a);

  REQUIRE(a_i.get_g() != NULL);
  REQUIRE(a_i.get_g()->get_g() != NULL);
  REQUIRE(a_i.get_g()->get_g()->get_g() != NULL);
  REQUIRE(a_i.get_g()->get_g()->get_g()->get_g() == &a_i);
}

//   // node point to the same
TEST_CASE("Struct complex diamond SmartPointer ",
          "[Struct][complex][SmartPointer][diamond]") {

  //            /--null
  //       /-b-<     /--null
  //    a-<     >-d-<
  //       L-c-<     L--null
  //            L--null

  Node2 n2a;
  Node2 n2a_i;
  n2a.a_g() = std::make_shared<Node2>();
  n2a.a_d() = std::make_shared<Node2>();

  auto n = std::make_shared<Node2>();
  n2a.a_g()->a_g() = nullptr;
  n2a.a_g()->a_d() = n;
  n2a.a_d()->a_g() = n;
  n2a.a_d()->a_d() = nullptr;

  std::stringstream ss;
  ss << n2a;
  ss >> n2a_i;

  REQUIRE(n2a_i.get_g() != nullptr);
  REQUIRE(n2a_i.get_d() != nullptr);
  REQUIRE(n2a_i.a_g()->get_g() == nullptr);
  REQUIRE(n2a_i.a_d()->get_d() == nullptr);
  REQUIRE(n2a_i.a_g()->get_d() == n2a_i.a_d()->get_g());
}

TEST_CASE("Struct complex circular SmartPointer ",
          "[Struct][complex][SmartPointer][circular]") {
  // a -> b -> c -> d -+
  // L---<----<---<---/
  auto n2a1 = std::make_shared<Node2>();
  auto n2a2 = std::make_shared<Node2>();
  auto n2a3 = std::make_shared<Node2>();
  auto n2a4 = std::make_shared<Node2>();

  n2a1->a_g() = n2a2;
  n2a2->a_g() = n2a3;
  n2a3->a_g() = n2a4;
  n2a4->a_g() = n2a1;

  std::shared_ptr<Node2> a_i;
  std::stringstream ss;
  ss << n2a1;
  ss >> a_i;

  INFO("a = " << n2a1);

  REQUIRE(a_i != nullptr);
  REQUIRE(a_i->get_g() != nullptr);
  REQUIRE(a_i->get_g()->get_g() != nullptr);
  REQUIRE(a_i->get_g()->get_g()->get_g() != nullptr);
  REQUIRE(a_i->get_g()->get_g()->get_g()->get_g() == a_i);
}
