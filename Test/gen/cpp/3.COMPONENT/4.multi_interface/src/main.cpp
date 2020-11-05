#include "Components/S_C1.hpp"
#include "Components/S_C2.hpp"
#include "Components/S_C3.hpp"
#include "Components/S_C4.hpp"

#include "catch.hpp"
#include "Data/code.hpp"

TEST_CASE("Component multi_interface", "[Component][multi_interface]") {
  S_C1 c1;

  S_C2 c2_a, c2_b, c2_c, c2_d;
  S_C3 c3_a, c3_b, c3_c, c3_d;
  S_C4 c4_a, c4_b, c4_c, c4_d;

  c1.r1_list.add(&c2_a.get_p());
  c1.r1_list.add(&c2_b.get_p());
  c1.r1_list.add(&c2_c.get_p());
  c1.r1_list.add(&c2_d.get_p());

  REQUIRE(c1.r1_list[0]->call1() == 0);
  REQUIRE(c1.r1_list[1]->call1() == 0);
  REQUIRE(c1.r1_list[2]->call1() == 0);
  REQUIRE(c1.r1_list[3]->call1() == 0);
  REQUIRE(c1.r1_list.size() == 4);

  REQUIRE_THROWS(c1.r1_list[4]->call1());
  REQUIRE_THROWS(c1.r1_list[100]->call1());

  // add link interface
  c1.r1_list.add(&c4_a.get_p());
  c1.r1_list.add(&c4_b.get_p());
  c1.r1_list.add(&c4_c.get_p());
  c1.r1_list.add(&c4_d.get_p());
  REQUIRE(c1.r1_list[4]->call1() == 0);
  REQUIRE(c1.r1_list[5]->call1() == 0);
  REQUIRE(c1.r1_list[6]->call1() == 0);
  REQUIRE(c1.r1_list[7]->call1() == 0);
  REQUIRE(c1.r1_list.size() == 8);

  //
  c1.r2_list.add(&c3_a.get_p());
  c1.r2_list.add(&c3_b.get_p());
  c1.r2_list.add(&c3_c.get_p());
  c1.r2_list.add(&c3_d.get_p());

  c1.r3_list.add(&c4_a.get_p());
  c1.r3_list.add(&c4_b.get_p());
  c1.r3_list.add(&c4_c.get_p());
  c1.r3_list.add(&c4_d.get_p());


}
