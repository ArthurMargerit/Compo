#include "Deployments/D_sync_server/D_sync_server.hpp"

#include "Links/S_in_fifo/S_in_fifo.hpp"
#include "Components/C_p.hpp"
#include "catch.hpp"
#include "Data/code.hpp"

TEST_CASE("Link fifo", "[Link][fifo]") {

  S_in_fifo s;
  s.set_path_in("server.in");
  s.set_path_out("server.out");

  C_p p;
  s.set_in(&p.get_ii());

  s.connect();
  s.step();
  s.disconnect();

  // D_sync_server ds;
  // ds.init();
  // ds.configuration();
  // ds.link();
  // ds.start();
  // ds.stop();
  // ds.quit();

}
