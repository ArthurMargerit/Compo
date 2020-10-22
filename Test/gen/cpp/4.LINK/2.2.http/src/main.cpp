#include "Deployments/D_http_server/D_http_server.hpp"
#include "Interfaces/I1/I1.hpp"
#include "Links/CompoMe/Posix/Http_client_out/Http_client_out.hpp"
#include "catch_thread.hpp"
#include <mutex>
#include <thread>


void client(std::string c = "", std::string i = "") {
  CompoMe::Posix::Http_client_out client;
  client.set_addr("127.0.0.1");
  client.set_port(8081);

  client.set_to_component(c);
  client.set_to_interface(i);

  CompoMe::Require_helper_t<I1> r;
  client.set_out(r);

  client.connect();
  for (int i = 0; i < 20000; i++) {
    r->f1();
    REQUIRE(r->f2() == 1);
    REQUIRE(r->f3(i) == i + 1);
    REQUIRE(r->f4(i, i * 2) == i + i * 2 + 1);
  }

  client.disconnect();
}


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
    //client 1
    client();
    //client 2
    client();
    // client 3
    client();
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

  lock.unlock();
  t2.join();


  d.stop();
  d.quit();
}
