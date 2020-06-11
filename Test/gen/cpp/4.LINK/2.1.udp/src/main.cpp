#include "catch.hpp"

#include "Links/S_udp_server/S_udp_server.hpp"
#include "Links/S_udp_client/S_udp_client.hpp"

#include "Components/C_p.hpp"
#include "Components/C_r.hpp"

TEST_CASE("Link simple", "[Link][simple]") {
  C_p p;

  S_udp_server server;
  server.set_addr("127.0.0.1");
  server.set_port(8080);
  server.set_in(&p.get_ii());
  server.connect();

  while (true) {
    server.step();
  }

  server.disconnect();
}


TEST_CASE("Link simple client", "[Link][Simple][Client]") {
  C_r r;

  S_udp_client client;
  client.set_addr("127.0.0.1");
  client.set_port(8080);
  client.set_out(r.io);
  client.connect();

  r.io->f1();
  r.io->f2();
  r.io->f3(1);
  r.io->f4(1,2);

  client.disconnect();
}
