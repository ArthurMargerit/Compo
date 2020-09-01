#include "Interfaces/I1/I1.hpp"
#include "Links/Dbus_client/Dbus_client.hpp"
#include "catch_thread.hpp"
#include <unistd.h>

TEST_CASE("call a", "[a]") {
  system("killall -9 dbus_server_test ; ./dbus_server_test &");
  sleep(2);

  DBus::init();
  Dbus_client client;
  client.set_object_name("/Compo/Client");
  client.set_timeout(1000);
  client.connect();

  CompoMe::Require_helper_t<I1> r;
  client.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r);

  for (i32 i = 0; i < 1000; ++i) {
    REQUIRE_NOTHROW(r->f2(i));
  }

  i32 v = r->f3();
  for (i32 i = 1; i < 1000; ++i) {
    REQUIRE(r->f3() == ++v);
  }

  for (i32 i = 0; i < 1000; ++i) {
    REQUIRE(r->f4(i) == i + 1);
  }

  for (i32 i = 0; i < 1000; ++i) {
    REQUIRE(r->f5(i, 1000 - i) == i + (1000 - i) + 2);
  }

  for (i32 i = 0; i < 1000; ++i) {
    REQUIRE_NOTHROW(r->set_a(i));
    REQUIRE(r->get_a() == i);
  }

  for (i32 i = 0; i < 1000; ++i) {
    REQUIRE_NOTHROW(r->set_b(i));
    REQUIRE(r->get_b() == i);
  }

  // will exit the server
  r->f1();
  sleep(1);
}

TEST_CASE("call 2 a", "[a]") {
  system("killall -9 dbus_server_test; ./dbus_server_test &");
  sleep(2);

  DBus::init();
  Dbus_client client1;
  client1.set_object_name("/Compo/Client1");
  client1.set_timeout(1000);
  client1.connect();

  Dbus_client client2;
  client2.set_object_name("/Compo/Client2");
  client2.set_timeout(1000);
  client2.connect();

  Dbus_client client3;
  client3.set_object_name("/Compo/Client3");
  client3.set_timeout(1000);
  client3.connect();

  CompoMe::Require_helper_t<I1> r1;
  client1.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r1);
  CompoMe::Require_helper_t<I1> r2;
  client2.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r2);
  CompoMe::Require_helper_t<I1> r3;
  client3.set_out("Compo.Server", "/Compo/Server/A", "I1.A", r3);

  for (i32 i = 0; i < 1000; ++i) {
    REQUIRE_NOTHROW(r1->set_a(i));
    REQUIRE_NOTHROW(r2->set_b(1000 - i));

    REQUIRE(r3->get_a() == i);
    REQUIRE(r3->get_b() == 1000 - i);
  }

  i32 v = r1->f3();
  for (i32 i = 0; i < 1000; ++i) {
    REQUIRE(r1->f3() == ++v);
    REQUIRE(r2->f3() == ++v);
    REQUIRE(r3->f3() == ++v);
  }

  // will exit the server
  r1->f1();
  sleep(1);

  client1.disconnect();
  REQUIRE(r1.connected() == false);

  client2.disconnect();
  REQUIRE(r2.connected() == false);

  client3.disconnect();
  REQUIRE(r3.connected() == false);
}