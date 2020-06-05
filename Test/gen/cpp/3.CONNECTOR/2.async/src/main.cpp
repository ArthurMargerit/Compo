#include "Components/C1.hpp"
#include "Components/C2.hpp"

#include "Data/code.hpp"
#include "catch.hpp"
#include "connectors/Math_async_simple.hpp"

TEST_CASE("Connector async", "[Connector][async]") {
  C1 c1;
  C2 c2;
  Math_async_simple b;

  b.rr.set(&c2.get_back_call());
  b.r.set(&c1.get_p());
  c2.call.set(&b.get_c());

  c1.configuration();
  c2.configuration();

  c1.connection();
  c2.connection();

  c1.start();
  c2.start();

  c1.step();
  c2.step();

  c1.stop();
  c2.stop();
}
