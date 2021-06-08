#include "Interfaces/I1/I1.hpp"
#include "Links/Dbus_client/Dbus_client.hpp"
#include "catch.hpp"
#include <mutex>
#include <unistd.h>

std::mutex mylockapp;
#define REQUIRE_LOCK(TEST)                                                     \
  mylockapp.lock();                                                            \
  REQUIRE(TEST);                                                               \
  mylockapp.unlock();

#define REQUIRE_LOCK_NOTHROW(TEST)                                             \
  mylockapp.lock();                                                            \
  REQUIRE_NOTHROW(TEST);                                                       \
  mylockapp.unlock();

const unsigned int _NB_TEST_ = 1000;

TEST_CASE("call a", "[a]") {
  system("killall -9 dbus_server_test ; ./dbus_server_test &");
  sleep(2);

  //  DBus::init();
  Dbus_client client;
  client.set_object_name("Compo.Client");
  client.set_timeout(1000);
  client.main_connect();

  CompoMe::Require_helper_t<I1> r;
  client.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                   r);

  for (i32 i = 0; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK_NOTHROW(r->f2(i));
  }

  i32 v = r->f3();
  for (i32 i = 1; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK(r->f3() == ++v);
  }

  for (i32 i = 0; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK(r->f4(i) == i + 1);
  }

  for (i32 i = 0; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK(r->f5(i, _NB_TEST_ - i) == i + (_NB_TEST_ - i) + 2);
  }

  for (i32 i = 0; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK_NOTHROW(r->set_a(i));
    REQUIRE_LOCK(r->get_a() == i);
  }

  for (i32 i = 0; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK_NOTHROW(r->set_b(i));
    REQUIRE_LOCK(r->get_b() == i);
  }

  // will exit the server
  r->f1();
  client.main_disconnect();
  sleep(1);
}

TEST_CASE("client connection instanciation with before", "[a]") {
  Dbus_client client;
  CompoMe::Require_helper_t<I1> r1;
  client.set_object_name("Compo.Client_multi");
  client.set_timeout(1000);
  client.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                   r1);
  REQUIRE_LOCK(r1.connected() != true);
  client.main_connect();
  REQUIRE_LOCK(r1.connected() == true);
  client.main_disconnect();
  REQUIRE_LOCK(r1.connected() != true);
}

TEST_CASE("client connection instanciation", "[a]") {
  Dbus_client client;
  client.set_object_name("Compo.Client_multi");
  client.set_timeout(1000);
  client.main_connect();

  SECTION("no client") {}

  SECTION("connect/remove/connect") {
    CompoMe::Require_helper_t<I1> r1;
    client.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                     r1);

    REQUIRE_LOCK(r1.connected() == true);

    client.main_disconnect();
    REQUIRE_LOCK(r1.connected() != true);

    client.main_connect();
    REQUIRE_LOCK(r1.connected() == true);

    client.main_disconnect();
    REQUIRE_LOCK(r1.connected() != true);

    client.main_connect();
    REQUIRE_LOCK(r1.connected() == true);

    client.main_disconnect();
    REQUIRE_LOCK(r1.connected() != true);

    client.main_disconnect();
  }

  // SECTION("add/remove/add") {
  //   CompoMe::Require_helper_t<I1> r1;

  //   client.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r1);
  //   REQUIRE_LOCK(r1.connected() == true);
  //   client.disconnect(r1);
  //   REQUIRE_LOCK(r1.connected() != true);

  //   client.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r1);
  //   REQUIRE_LOCK(r1.connected() == true);
  //   client.disconnect(r1);
  //   REQUIRE_LOCK(r1.connected() != true);

  //   client.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r1);
  //   REQUIRE_LOCK(r1.connected() == true);
  //   client.disconnect(r1);
  //   REQUIRE_LOCK(r1.connected() != true);

  //   client.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r1);
  //   REQUIRE_LOCK(r1.connected() == true);
  //   client.disconnect(r1);
  //   REQUIRE_LOCK(r1.connected() != true);
  // }

  SECTION("1 client") {
    CompoMe::Require_helper_t<I1> r1;
    client.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                     r1);
    client.main_disconnect();
  }

  SECTION("3 client") {
    CompoMe::Require_helper_t<I1> r1, r2, r3;
    client.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                     r1);
    client.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                     r2);
    client.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                     r3);
    client.main_disconnect();
  }
}

TEST_CASE("call 2 a", "[a]") {
  system("killall -9 dbus_server_test; ./dbus_server_test &");
  sleep(2);

  //  DBus::init();
  Dbus_client client1;
  client1.set_object_name("Compo.Client1");
  client1.set_timeout(1000);
  client1.main_connect();

  Dbus_client client2;
  client2.set_object_name("Compo.Client2");
  client2.set_timeout(1000);
  client2.main_connect();

  Dbus_client client3;
  client3.set_object_name("Compo.Client3");
  client3.set_timeout(1000);
  client3.main_connect();

  CompoMe::Require_helper_t<I1> r1;
  client1.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                    r1);
  CompoMe::Require_helper_t<I1> r2;
  client2.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                    r2);
  CompoMe::Require_helper_t<I1> r3;
  client3.get_bus().connect_require("Compo.Server", "/Compo/Server/A", "I1.A",
                                    r3);

  for (i32 i = 0; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK_NOTHROW(r1->set_a(i));
    REQUIRE_LOCK_NOTHROW(r2->set_b(1000 - i));

    REQUIRE_LOCK(r3->get_a() == i);
    REQUIRE_LOCK(r3->get_b() == 1000 - i);
  }

  i32 v = r1->f3();
  for (i32 i = 0; i < _NB_TEST_; ++i) {
    REQUIRE_LOCK(r1->f3() == ++v);
    REQUIRE_LOCK(r2->f3() == ++v);
    REQUIRE_LOCK(r3->f3() == ++v);
  }

  // will exit the server
  r1->f1();
  sleep(1);

  client1.main_disconnect();
  REQUIRE_LOCK(r1.connected() == false);

  client2.main_disconnect();
  REQUIRE_LOCK(r2.connected() == false);

  client3.main_disconnect();
  REQUIRE_LOCK(r3.connected() == false);
}
