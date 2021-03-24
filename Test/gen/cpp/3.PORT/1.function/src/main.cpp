
#include "Interfaces/I1/I1.hpp"
#include "Ports/Array_in.hpp"
#include "Ports/Array_out.hpp"
#include "Ports/In.hpp"
#include "Ports/Map_Map_in.hpp"
#include "Ports/Map_Map_out.hpp"
#include "Ports/Map_in.hpp"
#include "Ports/Map_out.hpp"
#include "Ports/Out.hpp"

#include "catch.hpp"

TEST_CASE("port in", "[Port]") {
  I1 i;

  In si;
  Array_in asi;
  Map_in msi;
  Map_Map_in mmsi;

  si.connect_interface(i);
  asi.connect_interface(1, i);
  msi.connect_interface("door", i);
  mmsi.connect_interface("car", "door", i);
}

TEST_CASE("port out", "[Port]") {
  CompoMe::Require_helper_t<I1> ri;

  Out so;
  Array_out aso;
  Map_out mso;
  Map_Map_out mmso;

  so.connect_require(ri);
  aso.connect_require(1, ri);
  mso.connect_require("door", ri);
  mmso.connect_require("car", "door", ri);
}
