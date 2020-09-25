#include "catch_thread.hpp"

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

#include "Links/CompoMe/Zmq/Zmq_client_out/Zmq_client_out.hpp"
#include "Links/CompoMe/Zmq/Zmq_server_in/Zmq_server_in.hpp"

#include "Components/C_p.hpp"
#include "Components/C_r.hpp"

#include "Deployments/D_zmq_server_multi/D_zmq_server_multi.hpp"

#define TEST_SERVER_ADDR "tcp://127.0.0.1:5555"
// #define TEST_SERVER_ADDR "ipc:///tmp/feed"

void client(CompoMe::String c = "", CompoMe::String i = "") {
  C_r r;
  CompoMe::Zmq::Zmq_client_out client;

  client.set_addr(TEST_SERVER_ADDR);
  client.set_to_component(c);
  client.set_to_interface(i);
  client.set_out(r.io);

  client.connect();
  for (int i = 0; i < 100; i++) {
    r.io->f1();
    REQUIRE(r.io->f2() == 1);
    REQUIRE(r.io->f3(i) == i + 1);
    REQUIRE(r.io->f4(i, i * 2) == i + i * 2 + 1);
  }

  client.disconnect();
}

TEST_CASE("Link simple with client", "[Link][simple]") {
  CompoMe::Zmq::Zmq_server_in server;
  server.set_bind_addr(TEST_SERVER_ADDR);

  std::mutex lock;
  lock.lock();

  C_p p;
  server.set_in(&p.get_ii());
  server.connect();

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

  server.disconnect();
}

TEST_CASE("Link Interface Many", "[Link][many_INTERFACE]") {
  D_zmq_server_multi d;
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
  SECTION("1 client") { client("", "h1"); }
  SECTION("3 client") {
    // client 1
    client("", "h1");
    // client 2
    client("", "h2");
    // client 3
    client("", "h3");
  }

  SECTION("3 client async") {
    std::thread tc_1([]() { client("", "h1"); });
    std::thread tc_2([]() { client("", "h1"); });
    std::thread tc_3([]() { client("", "h2"); });
    std::thread tc_4([]() { client("", "h2"); });
    std::thread tc_5([]() { client("", "h3"); });
    std::thread tc_6([]() { client("", "h3"); });
    tc_1.join();
    tc_2.join();
    tc_3.join();
    tc_4.join();
    tc_5.join();
    tc_6.join();
  }

  lock.unlock();
  t2.join();

  d.stop();
  d.quit();
}
