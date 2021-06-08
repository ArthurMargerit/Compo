#include "I1_i.hpp"
#include "Ports/CompoMe/Core/DCI_map_in.hpp"
#include "Ports/CompoMe/Core/DCI_map_out.hpp"
#include "catch.hpp"

TEST_CASE("Core DCI map port in", "[Port][Dest][Compo][Inter]") {
  CompoMe::Core::DCI_map_in in;
  I1_i i;
  REQUIRE(in.is_connected_interface("lapin", "lapin", "lapin") == false);
  REQUIRE(in.is_connected_interface(i) == false);

  // connect
  REQUIRE(in.connect_interface("A", "B", "C", i) == true);
  REQUIRE(in.is_connected_interface("A", "B", "C") == true);
  REQUIRE(in.is_connected_interface(i) == true);

  // get
  REQUIRE(&in.get_interface("A", "B", "C") == &i);

  // disconnect
  REQUIRE(in.disconnect_interface("A", "B", "C") == true);
  REQUIRE(in.is_connected_interface("A", "B", "C") == false);
  REQUIRE(in.is_connected_interface(i) == false);
}

TEST_CASE("Core DCI map port out", "[Port][Dest][Compo][Inter]") {
  CompoMe::Core::DCI_map_out out;
  CompoMe::Require_helper_t<I1> ri;
  REQUIRE(out.is_connected_require("lapin", "lapin", "lapin") == false);
  REQUIRE(out.is_connected_require(ri) == false);

  // connect
  REQUIRE(out.connect_require("A", "B", "C", ri) == true);
  REQUIRE(out.is_connected_require("A", "B", "C") == true);
  REQUIRE(out.is_connected_require(ri) == true);

  // get
  REQUIRE(&out.get_require("A", "B", "C") == &ri);

  // disconnect
  REQUIRE(out.disconnect_require("A", "B", "C") == true);
  REQUIRE(out.is_connected_require("A", "B", "C") == false);
  REQUIRE(out.is_connected_require(ri) == false);
}
