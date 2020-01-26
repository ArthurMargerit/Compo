
#include "Links/S_in/S_in.hpp"
#include "Links/S_out/S_out.hpp"

#include "Components/C1/C1.hpp"
#include "Components/C2/C2.hpp"

int main() {

  C1::C1 c1;
  C2::C2 c2;

  S_in sin;
  S_out sout;

  sin.set_in(&c1.get_ia());
  sout.set_out(c2.fake_ia());

  sin.connect();
  sout.connect();

  for (int i = 0; i < 100; ++i) {
    sin.step();
    sout.step();
  }

  sin.disconnect();
  sout.disconnect();
  return 0;
}
