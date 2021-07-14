#include "Data/code.hpp"
#include "Deployments/D_tcp_server/D_tcp_server.hpp"
#include "Errors/E1.hpp"
#include "Interfaces/I1/I1.hpp"
#include "Links/CompoMe/Posix/Tcp_client_out/Tcp_client_out.hpp"
#include "catch.hpp"
#include <mutex>
#include <string>
#include <thread>

std::mutex mylockapp;
#define REQUIRE_LOCK(TEST)                                                     \
  mylockapp.lock();                                                            \
  REQUIRE(TEST);                                                               \
  mylockapp.unlock();

#define REQUIRE_LOCK_THROWS(TEST)                                              \
  mylockapp.lock();                                                            \
  REQUIRE_THROWS(TEST);                                                        \
  mylockapp.unlock();

#define REQUIRE_LOCK_NOTHROW(TEST)                                             \
  mylockapp.lock();                                                            \
  REQUIRE_NOTHROW(TEST);                                                       \
  mylockapp.unlock();

void client_error(std::string c = "", std::string i = "") {

  CompoMe::Posix::Tcp_client_out client;
  client.set_addr("127.0.0.1");
  client.set_port(1500);

  client.set_to_component(c);
  client.set_to_interface(i);

  CompoMe::Require_helper_t<I1> r;
  client.get_main().connect_require(r);

  client.main_connect();

  REQUIRE_LOCK_THROWS(r->call_a_function_that_throw_an_error1());
  REQUIRE_LOCK_THROWS(r->call_a_function_that_throw_an_error2(1));
  REQUIRE_LOCK_THROWS(r->call_a_function_that_throw_an_error3(2, "test"));

  try {
    r->call_a_function_that_throw_an_error3(2, "is in place");
  } catch (E1 &e) {
    INFO(e);
    REQUIRE_LOCK(e.get_msg() == "Error is in place");
    REQUIRE_LOCK(e.get_val() == 1);
  }

  client.main_disconnect();
}

void client(std::string c = "", std::string i = "") {

  CompoMe::Posix::Tcp_client_out client;
  client.set_addr("127.0.0.1");
  client.set_port(1500);

  client.set_to_component(c);
  client.set_to_interface(i);

  CompoMe::Require_helper_t<I1> r;
  client.get_main().connect_require(r);

  client.main_connect();
  for (int i = 0; i < 2000; i++) {
    r->f1();
    REQUIRE_LOCK(r->f2() == 1);
    REQUIRE_LOCK(r->f3(i) == i + 1);
    REQUIRE_LOCK(r->f4(i, i * 2) == i + i * 2 + 1);
  }

  client.main_disconnect();
}

TEST_CASE("Link tcp server", "[Link][tcp]") {
  init_code();
  D_tcp_server d;
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
  SECTION("client error") { client_error(); }
  SECTION("2 client") {
    // client 1
    client();
    // client 2
    client();
    // client 3
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

  d.stop();
  d.quit();
}
