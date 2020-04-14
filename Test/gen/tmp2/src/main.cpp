#include "Deployments/D_sync_server/D_sync_server.hpp"

#include "Components/C_p/C_p.hpp"
#include "Links/S_in_fifo/S_in_fifo.hpp"
#include <unistd.h>
int main(int argc, char *argv[]) {

  S_in_fifo s;
  s.set_path_in("server.in");
  s.set_path_out("server.out");

  C_p::C_p p;
  s.set_in(&p.get_ii());

  s.connect();
  while (true) {
    sleep(1);
    s.step();
  }
  s.disconnect();

  return 0;
}
