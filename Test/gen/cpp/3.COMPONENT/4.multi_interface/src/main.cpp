#include "Components/S_C1/S_C1.hpp"
#include "Components/S_C2/S_C2.hpp"
#include "Components/S_C3/S_C3.hpp"
#include "Components/S_C4/S_C4.hpp"

#include "catch.hpp"
#include "Data/code.hpp"

TEST_CASE("Component multi_interface", "[Component][multi_interface]") {
  S_C1::S_C1 c1;

  S_C2::S_C2 c2_a;
  S_C2::S_C2 c2_b;
  S_C2::S_C2 c2_c;
  S_C2::S_C2 c2_d;
  c1.add_r1_list(&c2_a.get_p());
  c1.add_r1_list(&c2_b.get_p());
  c1.add_r1_list(&c2_c.get_p());
  c1.add_r1_list(&c2_d.get_p());

  S_C3::S_C3 c3_a;
  S_C3::S_C3 c3_b;
  S_C3::S_C3 c3_c;
  S_C3::S_C3 c3_d;
  c1.add_r2_list(&c3_a.get_p());
  c1.add_r2_list(&c3_b.get_p());
  c1.add_r2_list(&c3_c.get_p());
  c1.add_r2_list(&c3_d.get_p());

  S_C4::S_C4 c4_a;
  S_C4::S_C4 c4_b;
  S_C4::S_C4 c4_c;
  S_C4::S_C4 c4_d;
  c1.add_r3_list(&c4_a.get_p());
  c1.add_r3_list(&c4_b.get_p());
  c1.add_r3_list(&c4_c.get_p());
  c1.add_r3_list(&c4_d.get_p());

  c1.step();

}
