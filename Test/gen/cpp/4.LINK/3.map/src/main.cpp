
#include "Links/S_in/S_in.hpp"
#include "Links/S_out/S_out.hpp"

#include "Components/C1.hpp"
#include "Components/C2.hpp"
#include "Deployments/D/D.hpp"

#include "catch.hpp"
#include "Data/code.hpp"

void without_dep() {

  C1 c1;
  C2 c2;

  S_in sin;
  S_out sout;

  sin.set_in("lapin", &c1.get_ia());
  sout.set_out("lapin", c2.ia);

  sin.set_in("lion", &c1.get_ia());
  sout.set_out("lion", c2.ia);

  sin.set_in("cochon", &c1.get_ia());
  sout.set_out("cochon", c2.ia);

  sin.connect();
  sout.connect();

  for (int i = 0; i < 100; ++i) {
    sin.step();
    sout.step();
  }

  sin.disconnect();
  sout.disconnect();
}

void with_dep() {
  D d;
  d.init();
  d.configuration();
  d.link();
  d.start();

  for (int i = 0; i < 100; ++i) {
    d.step();
  }

  d.stop();
  d.quit();
}

TEST_CASE("Link map", "[Link][map]") {

  without_dep();
  with_dep();
}
