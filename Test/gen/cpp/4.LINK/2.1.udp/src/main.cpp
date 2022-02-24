#include "Components/C_p.hpp"

#include "Links/CompoMe/Posix/Udp_client_out/Udp_client_out.hpp"
#include "Links/CompoMe/Posix/Udp_server_in/Udp_server_in.hpp"
#include "catch.hpp"
#include <mutex>
#include <thread>

std::mutex mylockapp;
#define REQUIRE_LOCK(TEST)                                                     \
  mylockapp.lock();                                                            \
  REQUIRE(TEST);                                                               \
  mylockapp.unlock();

static std::mutex l;

/// client 1
void client() {
  CompoMe::Posix::Udp_client_out client;
  // S_udp_client client;
  client.set_addr("127.0.0.1");
  client.set_port(8080);

  CompoMe::Require_helper_t<I1> req;
  client.get_main().connect_require(req);

  client.main_connect();

  for (int i = 0; i < 10000; i++) {
    req->f1();
    REQUIRE_LOCK(req->f2() == 1);
    REQUIRE_LOCK(req->f3(i) == i + 1);
    REQUIRE_LOCK(req->f4(i, i * 2) == i + i * 2 + 1);
  }

  client.main_disconnect();
}

TEST_CASE("Link simple", "[Link][simple]") {
  std::mutex lock;
  lock.lock();

  C_p p;
  CompoMe::Posix::Udp_server_in server;

  server.set_addr("127.0.0.1");
  server.set_port(8080);
  server.set_poll_time(1000);
  server.get_main().connect_interface(p.get_ii());
  server.main_connect();

  std::thread t2([&server, &lock]() {
    while (!lock.try_lock()) {
      server.step();
    }
  });

  SECTION("0 client") {}

  SECTION("1 client") { client(); }

  SECTION("2 client") {
    // client 1
    client();
    // client 2
    client();
  }

  SECTION("client async ") {
    // client 1
    std::thread tc_1([]() { client(); });
    std::thread tc_2([]() { client(); });
    std::thread tc_3([]() { client(); });
    std::thread tc_4([]() { client(); });
    std::thread tc_5([]() { client(); });

    tc_1.join();
    tc_2.join();
    tc_3.join();
    tc_4.join();
    tc_5.join();
  }

  lock.unlock();
  t2.join();

  server.main_disconnect();
}
