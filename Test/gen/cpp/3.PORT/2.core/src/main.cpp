#include "I1_i.hpp"

#include "Ports/CompoMe/Core/in.hpp"
#include "Ports/CompoMe/Core/map_in.hpp"
#include "Ports/CompoMe/Core/map_out.hpp"
#include "Ports/CompoMe/Core/out.hpp"
#include "catch.hpp"

TEST_CASE("Core port in", "[Port]") {
  CompoMe::Core::in port_in;
  I1_i inter_i1, inter_i1_o;
  REQUIRE(port_in.is_connected_interface() == false);

  REQUIRE(port_in.connect_interface(inter_i1) == true);
  REQUIRE(port_in.is_connected_interface() == true);
  REQUIRE(port_in.is_connected_interface(inter_i1) == true);
  REQUIRE(port_in.is_connected_interface(inter_i1_o) == false);

  REQUIRE(port_in.connect_interface(inter_i1_o) == true);
  REQUIRE(port_in.is_connected_interface() == true);
  REQUIRE(port_in.is_connected_interface(inter_i1) == false);
  REQUIRE(port_in.is_connected_interface(inter_i1_o) == true);

  REQUIRE(port_in.disconnect_interface(inter_i1) == false);
  REQUIRE(port_in.disconnect_interface(inter_i1_o) == true);
  REQUIRE(port_in.is_connected_interface() == false);
}

TEST_CASE("Core port out", "[Port]") {
  CompoMe::Core::out port_out;
  CompoMe::Require_helper_t<I1> req_i1;
  CompoMe::Require_helper_t<I1> req_i1_o;

  REQUIRE(port_out.is_connected_require() == false);

  REQUIRE(port_out.connect_require(req_i1) == true);

  REQUIRE(port_out.is_connected_require() == true);
  REQUIRE(port_out.is_connected_require(req_i1) == true);
  REQUIRE(port_out.is_connected_require(req_i1_o) == false);

  REQUIRE(port_out.connect_require(req_i1_o) == true);
  REQUIRE(port_out.is_connected_require() == true);
  REQUIRE(port_out.is_connected_require(req_i1) == false);
  REQUIRE(port_out.is_connected_require(req_i1_o) == true);

  REQUIRE(port_out.disconnect_require(req_i1) == false);
  REQUIRE(port_out.disconnect_require(req_i1_o) == true);
  REQUIRE(port_out.is_connected_require() == false);
}

TEST_CASE("Core port map in", "[Port]") {
  I1_i ia, ib;
  CompoMe::Core::map_in port_map_in;

  // is connected
  REQUIRE(port_map_in.is_connected_interface(ia) == false);
  REQUIRE(port_map_in.is_connected_interface(ib) == false);
  REQUIRE(port_map_in.is_connected_interface("i1_a") == false);
  REQUIRE(port_map_in.is_connected_interface("i1_b") == false);

  // connect
  REQUIRE(port_map_in.connect_interface("i1_a", ia) == true);
  REQUIRE(port_map_in.connect_interface("i1_b", ib) == true);

  // is connected on key
  REQUIRE(port_map_in.is_connected_interface("i1_a") == true);
  REQUIRE(port_map_in.is_connected_interface("i1_b") == true);

  // is connected on interface
  REQUIRE(port_map_in.is_connected_interface(ia) == true);
  REQUIRE(port_map_in.is_connected_interface(ib) == true);

  // get test
  REQUIRE(&port_map_in.get_interface("i1_a") == &ia);
  REQUIRE(&port_map_in.get_interface("i1_a") != &ib);
  REQUIRE(&port_map_in.get_interface("i1_b") == &ib);
  REQUIRE(&port_map_in.get_interface("i1_b") != &ia);

  //// disconnect
  // disconnect by key
  REQUIRE(port_map_in.disconnect_interface(ia) == true);
  REQUIRE(port_map_in.is_connected_interface("i1_a") == false);
  REQUIRE(port_map_in.is_connected_interface(ia) == false);
  // disconnect by value
  REQUIRE(port_map_in.disconnect_interface("i1_b") == true);
  REQUIRE(port_map_in.is_connected_interface("i1_b") == false);
  REQUIRE(port_map_in.is_connected_interface(ib) == false);
}

TEST_CASE("Core port map out", "[Port]") {
  CompoMe::Core::map_out port_map_out;
  CompoMe::Require_helper_t<I1> req_i1;
  CompoMe::Require_helper_t<I1> req_i1_o;

  INFO("At start " << port_map_out.get_require_list());
  // is connected
  REQUIRE(port_map_out.is_connected_require(req_i1) == false);
  REQUIRE(port_map_out.is_connected_require(req_i1_o) == false);
  REQUIRE(port_map_out.is_connected_require("i1_a") == false);
  REQUIRE(port_map_out.is_connected_require("i1_b") == false);

  // connect
  REQUIRE(port_map_out.connect_require("i1_a", req_i1) == true);
  REQUIRE(port_map_out.connect_require("i1_b", req_i1_o) == true);

  INFO("After connection " << port_map_out.get_require_list());
  // is connected on key
  REQUIRE(port_map_out.is_connected_require("i1_a") == true);
  REQUIRE(port_map_out.is_connected_require("i1_b") == true);

  // is connected on interface
  REQUIRE(port_map_out.is_connected_require(req_i1) == true);
  REQUIRE(port_map_out.is_connected_require(req_i1) == true);

  // get test
  REQUIRE(&port_map_out.get_require("i1_a") == &req_i1);
  REQUIRE(&port_map_out.get_require("i1_a") != &req_i1_o);
  REQUIRE(&port_map_out.get_require("i1_b") == &req_i1_o);
  REQUIRE(&port_map_out.get_require("i1_b") != &req_i1);

  //// disconnect
  // disconnect by key
  REQUIRE(port_map_out.disconnect_require(req_i1) == true);
  REQUIRE(port_map_out.is_connected_require("i1_a") == false);
  REQUIRE(port_map_out.is_connected_require(req_i1) == false);
  // disconnect by value
  REQUIRE(port_map_out.disconnect_require("i1_b") == true);
  REQUIRE(port_map_out.is_connected_require("i1_b") == false);
  REQUIRE(port_map_out.is_connected_require(req_i1_o) == false);
}
