#include "Components/C_p.hpp"
#include "Components/C_r.hpp"

#include "Data/code.hpp"

#include "Links/S_in_fifo/S_in_fifo.hpp"
#include "Links/S_out_fifo/S_out_fifo.hpp"

#include "catch.hpp"
#include <fcntl.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

TEST_CASE("Link fifo server", "[Link][Fifo][Server]") {
  C_p p;

  S_in_fifo s;
  s.set_path_in("server.in");
  s.set_path_out("server.out");
  s.set_in(&p.get_ii());

  s.connect();

  // No Client ////////////////////////////////////////////////////////////////
  s.step();

  // No Client 100
  // ////////////////////////////////////////////////////////////////
  for (int i = 0; i < 100; ++i) {
    s.step();
  }

  // client simulation
  // open question
  std::ofstream ofs("server.in");
  // f1 ///////////////////////////////////////////////////////////////////////
  ofs << "f1()" << std::endl;
  // open answer
  int ifd = open("server.out", O_RDONLY | O_NONBLOCK);
  // step the server
  s.step();
  // read the answer
  char a;
  int r = read(ifd, &a, 1);
  // check f1
  REQUIRE(r == 0);
  close(ifd);

  // f2 ///////////////////////////////////////////////////////////////////////
  ofs << "f2()" << std::endl;
  // open answer
  ifd = open("server.out", O_RDONLY | O_NONBLOCK);
  // step the server
  s.step();
  // read the answer
  r = read(ifd, &a, 1);
  // check f1
  REQUIRE(r == 1);
  REQUIRE(a == '0');
  close(ifd);

  // f3 ///////////////////////////////////////////////////////////////////////
  ofs << "f3(1)" << std::endl;
  // open answer
  ifd = open("server.out", O_RDONLY | O_NONBLOCK);
  // step the server
  s.step();
  // read the answer
  r = read(ifd, &a, 1);
  // check f1
  REQUIRE(r == 1);
  REQUIRE(a == '0');
  close(ifd);

  // f4 ///////////////////////////////////////////////////////////////////////
  ofs << "f4(1,2)" << std::endl;
  // open answer
  ifd = open("server.out", O_RDONLY | O_NONBLOCK);
  // step the server
  s.step();
  // read the answer
  r = read(ifd, &a, 1);
  // check f1
  REQUIRE(r == 1);
  REQUIRE(a == '0');
  close(ifd);

  s.disconnect();
}

// TEST_CASE("Link fifo client", "[Link][Fifo][Client]") {
//   C_r r;

//   S_out_fifo s;
//   s.set_path_out("server.in");
//   s.set_path_in("server.out");
//   s.set_out(r.io);

//   s.connect();
//   for (int i = 0; i < 100; ++i) {
//     s.step();
//   }
//   s.disconnect();
// }
