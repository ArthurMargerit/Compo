#include "Deployments/D_http_server/D_http_server.hpp"
#include "Interfaces/I1/I1.hpp"
#include "Links/CompoMe/Posix/Http_client_out/Http_client_out.hpp"
#include "catch.hpp"
#include <mutex>
#include <thread>

std::mutex mylockapp;
#define REQUIRE_LOCK(TEST)                                                     \
  mylockapp.lock();                                                            \
  REQUIRE(TEST);                                                               \
  mylockapp.unlock();

void client_many(int port = 8081, std::vector<std::string> inte={}) {
  CompoMe::Posix::Http_client_out client;

  client.set_addr("127.0.0.1");
  client.set_port(port);
  client.set_to("");

  client.main_connect();
  std::vector<CompoMe::Require_helper_t<I1>> r(inte.size());
  for (unsigned int i = 0; i < inte.size(); ++i) {
    client.get_many().connect_require(inte[i], r[i]);
  }

  for (unsigned int j = 0; j < r.size(); j++) {
    REQUIRE_LOCK(r[j].connected());
  }

  for (unsigned int j = 0; j < r.size(); j++) {
    for (int i = 0; i < 2000; i++) {
      r[j]->f1();
      REQUIRE_LOCK(r[j]->f2() == 1);
      REQUIRE_LOCK(r[j]->f3(i) == i + 1);
      REQUIRE_LOCK(r[j]->f4(i, i * 2) == i + i * 2 + 1);
    }
  }

  client.main_disconnect();
}

void client(int port = 8081, std::string to = "") {
  CompoMe::Posix::Http_client_out client;

  client.set_addr("127.0.0.1");
  client.set_port(port);
  client.set_to(to);

  client.main_connect();
  CompoMe::Require_helper_t<I1> r;
  if (to == "")
    client.get_main().connect_require(r);
  else
    client.get_many().connect_require(to, r);

  REQUIRE_LOCK(r.connected());
  // r->f1();
  for (int i = 0; i < 2000; i++) {
    r->f1();
    REQUIRE_LOCK(r->f2() == 1);
    REQUIRE_LOCK(r->f3(i) == i + 1);
    REQUIRE_LOCK(r->f4(i, i * 2) == i + i * 2 + 1);
  }

  client.main_disconnect();
}

#include <iostream>

TEST_CASE("Link tcp server", "[Link][tcp]") {
  D_http_server d;
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

  SECTION("0 client") {}
  SECTION("1 client") { client(); }

  SECTION("2 client") {
    // client 1
    client();
    // client 2
    client();
    // client 3
    client();
  }

  SECTION("2 client") {
    // client 1
    client_many(8081, {"/", "/i1", "/i2", "/i/3"});
    // client 2
    client_many(8081, {"/", "/i1", "/i2", "/i1", "/i/3", "/", "/i1", "/i2",
                       "/i1", "/i/3", "/", "/i1", "/i2", "/i1", "/i/3"});
  }

  SECTION("client async ") {
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

  SECTION("client to map async") {
    std::thread tc_1([]() { client(8081, "/i1"); });
    std::thread tc_2([]() { client(8081, "/i2"); });
    std::thread tc_3([]() { client(8081, "/i1"); });
    std::thread tc_4([]() { client(8081, "/i2"); });
    std::thread tc_5([]() { client(8081, "/i/3"); });

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
