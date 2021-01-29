#include "Deployments/D_https_server/D_https_server.hpp"
#include "Interfaces/I1/I1.hpp"
#include "Links/CompoMe/Posix/Https_client_out/Https_client_out.hpp"
#include "catch.hpp"
#include <mutex>
#include <string>
#include <thread>

std::mutex mylockapp;
#define REQUIRE_LOCK(TEST)                                                     \
  mylockapp.lock();                                                            \
  REQUIRE(TEST);                                                               \
  mylockapp.unlock();

void client(std::string to = "") {
  CompoMe::Posix::Https_client_out client;
  client.set_addr("127.0.0.1");
  client.set_port(10443);
  client.set_ca_cert_file("exp.cert");

  client.set_to(to);

  CompoMe::Require_helper_t<I1> r;
  client.set_out(r);

  client.connect();

  REQUIRE_LOCK(true == r.connected());
  for (int i = 0; i < 2000; i++) {
    r->f1();
    REQUIRE_LOCK(r->f2() == 1);
    REQUIRE_LOCK(r->f3(i) == i + 1);
    REQUIRE_LOCK(r->f4(i, i * 2) == i + i * 2 + 1);
  }

  client.disconnect();
}

TEST_CASE("Link tcp server", "[Link][tcp]") {
  D_https_server d;
  d.init();
  d.configuration();
  d.link();
  d.start();

  std::mutex lock;
  lock.lock();
  std::thread t2([&d, &lock]() {
    while (!lock.try_lock()) {
      d.step();
    }
  });

  SECTION("1 client") { client("test"); }

  SECTION("2 client") {
    // client 1
    client("test");
    // client 2
    client("test");
    // client 3
    client("test");
  }

  SECTION("client async ") {
    std::thread tc_1([]() { client("test"); });
    std::thread tc_2([]() { client("test"); });
    std::thread tc_3([]() { client("test"); });
    std::thread tc_4([]() { client("test"); });
    std::thread tc_5([]() { client("test"); });

    tc_1.join();
    tc_2.join();
    tc_3.join();
    tc_4.join();
    tc_5.join();
  }

  lock.unlock();
  t2.join();

  d.stop();
  d.quit();
}
