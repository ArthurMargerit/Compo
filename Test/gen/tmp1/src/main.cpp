#include "Deployments/D_sync_server/D_sync_server.hpp"

#include "Components/C_p/C_p.hpp"
#include "Components/C_r/C_r.hpp"
#include "Links/S_in_fifo/S_in_fifo.hpp"
#include "Links/S_out_fifo/S_out_fifo.hpp"
#include <string.h>
#include <unistd.h>

void server() {
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
}

void client() {
  S_out_fifo s;
  s.set_path_in("server.out");
  s.set_path_out("server.in");

  C_r::C_r r;
  s.set_out(r.io);

  s.connect();
  while (true) {
    sleep(1);
    std::cout << "f4()->" << r.io->f4() << "\n";
  }
  s.disconnect();
}

int main(int argc, char *argv[]) {
  if (argc != 2)
    return -1;

  if (strcmp(argv[1], "server") == 0) {
    server();
  }

  if (strcmp(argv[1], "client") == 0) {
    client();
  }

  return 0;
}
