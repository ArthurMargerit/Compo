#include "catch.hpp"

#include "Data/code.hpp"


TEST_CASE("Type template", "[Type][Template]") {
  // define
  sp_int sp1;
  up_int up2;

  f_add f1;
  f_none f2;

  array_of_int_10 aoi;
  list_of_int loi;
  vector_of_int voi;

  // dynamic
  Vec<int> v1;
  Pair<int,int> v2;
  Option<int> v3;
  Map<int,int> v4;
  Vec2D<int> v5;
  Vec3D<int> v6;

  // define with dynamic inside
  PairOfVec2D v7;

}
