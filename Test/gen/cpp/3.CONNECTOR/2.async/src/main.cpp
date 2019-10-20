#include "Components/C1/C1.hpp"
#include "Components/C2/C2.hpp"

#include "connectors/Math_async_simple.hpp"

int main() {
  C1::C1 c1;
  C2::C2 c2;
  Math_async_simple b;

  b.rr = &c2.get_back_call();
  b.r = &c1.get_p();
  c2.set_call(&b.c);

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
