#include "catch.hpp"

#include "Structs/Struct.hpp"
#include "Structs/AAAAAA.hpp"

#include "Data/code.hpp"
#include <sstream>

TEST_CASE("Struct Parent heritage get/set", "[Struct][Parent][Get/Set]") {
  init_code();
  AAAAAA a;
  a.set_a1(1);
  REQUIRE(a.get_a1() == 1);
  REQUIRE(a.a_a1() == 1);
  a.a_a1() = -1;
  REQUIRE(a.a_a1() == -1);

  a.set_a2(2);
  REQUIRE(a.get_a2() == 2);
  REQUIRE(a.a_a2() == 2);
  a.a_a2() = -2;
  REQUIRE(a.a_a2() == -2);

  a.set_a3(3);
  REQUIRE(a.get_a3() == 3);
  REQUIRE(a.a_a3() == 3);
  a.a_a3() = -3;
  REQUIRE(a.a_a3() == -3);

  a.set_a4(4);
  REQUIRE(a.get_a4() == 4);
  REQUIRE(a.a_a4() == 4);
  a.a_a4() = -4;
  REQUIRE(a.a_a4() == -4);

  a.set_a5(5);
  REQUIRE(a.get_a5() == 5);
  REQUIRE(a.a_a5() == 5);
  a.a_a5() = -5;
  REQUIRE(a.a_a5() == -5);

  a.set_a6(6);
  REQUIRE(a.get_a6() == 6);
  REQUIRE(a.a_a6() == 6);
  a.a_a5() = -6;
  REQUIRE(a.a_a5() == -6);
}

TEST_CASE("Struct Parent heritage ClassPoly", "[Struct][Parent][Poly]") {
  AAAAAA a;
  a.set_a1(1);
  a.set_a2(2);
  a.set_a3(3);
  a.set_a4(4);
  a.set_a5(5);
  a.set_a6(6);

  AAAAAA *p1 = NULL;
  AAAAA *p2 = NULL;
  AAAA *p3 = NULL;
  AAA *p4 = NULL;
  AA *p5 = NULL;
  A *p6 = NULL;
  CompoMe::Struct *p7 = NULL;

  p1 = dynamic_cast<AAAAAA *>(&a);
  REQUIRE(p1 != nullptr);
  REQUIRE(p1->get_a6() == 6);

  p2 = dynamic_cast<AAAAA *>(&a);
  REQUIRE(p2 != nullptr);
  REQUIRE(p2->get_a5() == 5);

  p3 = dynamic_cast<AAAA *>(&a);
  REQUIRE(p3 != nullptr);
  REQUIRE(p3->get_a4() == 4);

  p4 = dynamic_cast<AAA *>(&a);
  REQUIRE(p4 != nullptr);
  REQUIRE(p4->get_a3() == 3);

  p5 = dynamic_cast<AA *>(&a);
  REQUIRE(p5 != nullptr);
  REQUIRE(p5->get_a2() == 2);

  p6 = dynamic_cast<A *>(&a);
  REQUIRE(p6 != nullptr);
  REQUIRE(p6->get_a1() == 1);

  p7 = dynamic_cast<CompoMe::Struct *>(&a);
  REQUIRE(p7 != nullptr);
}

TEST_CASE("Struct Parent Serialization",
          "[Struct][Parent][Poly][Serialization]") {
  std::stringstream ss;
  AAAAAA a;
  ss << a;
  INFO("A: " << a);

  auto p = ss.str().find("type:AAAAAA");
  REQUIRE(p != std::string::npos);
  p = ss.str().find("type:AAAAA");
  REQUIRE(p != std::string::npos);
  p = ss.str().find("type:AAAA");
  REQUIRE(p != std::string::npos);
  p = ss.str().find("type:AAA");
  REQUIRE(p != std::string::npos);
  p = ss.str().find("type:AA");
  REQUIRE(p != std::string::npos);
  p = ss.str().find("type:A");
  REQUIRE(p != std::string::npos);
}

TEST_CASE("Struct Parent Serialization 2",
          "[Struct][Parent][Poly][Serialization]") {

  std::stringstream ss;
  AAAAAA a_e, a_i;
  a_e.set_a6(6);
  a_e.set_a5(5);
  a_e.set_a4(4);
  a_e.set_a3(3);
  a_e.set_a2(2);
  a_e.set_a1(1);

  ss << a_e;
  ss >> a_i;

  REQUIRE(a_i.get_a1() == 1);
  REQUIRE(a_i.get_a2() == 2);
  REQUIRE(a_i.get_a3() == 3);
  REQUIRE(a_i.get_a4() == 4);
  REQUIRE(a_i.get_a5() == 5);
  REQUIRE(a_i.get_a6() == 6);
}

TEST_CASE("Struct Parent Serialization dynamic cast",
          "[Struct][Parent][Poly][Serialization]") {

  AAAAAA *a = new AAAAAA();
  REQUIRE(a != NULL);

  AAAAA *p1 = dynamic_cast<AAAAA *>(a);
  REQUIRE(p1 != NULL);

  AAAA *p2 = dynamic_cast<AAAA *>(a);
  REQUIRE(p2 != NULL);

  AAA *p3 = dynamic_cast<AAA *>(a);
  REQUIRE(p3 != NULL);

  AA *p4 = dynamic_cast<AA *>(a);
  REQUIRE(p4 != NULL);

  A *p5 = dynamic_cast<A *>(a);
  REQUIRE(p5 != NULL);
  delete (a);
}

TEST_CASE("Struct Parent Serialization cast", "[Struct][Parent][Poly][cast]") {

  A *a = new A();
  REQUIRE(a != NULL);

  AAAAA *p1 = dynamic_cast<AAAAA *>(a);
  REQUIRE(p1 == NULL);
  AAAA *p2 = dynamic_cast<AAAA *>(a);
  REQUIRE(p2 == NULL);
  AAA *p3 = dynamic_cast<AAA *>(a);
  REQUIRE(p3 == NULL);
  AA *p4 = dynamic_cast<AA *>(a);
  REQUIRE(p4 == NULL);
}
