
#include <thread>

#include "Interfaces/I1/I1.hpp"
#include "Interfaces/Wrong_Interface/Wrong_Interface.hpp"
#include "Links/Dbus_client/Dbus_client.hpp"
#include "Links/Dbus_server/Dbus_server.hpp"
#include <unistd.h>

std::mutex p_exit;

class I1_i : public I1 {
public:
  i32 get_b() const override { return b; }

  void set_b(const i32 &b) override { this->b = b; }

  i32 get_a() const override { return a; }

  void set_a(const i32 &a) override { this->a = a; }

  I1_i() : I1(), a(0), b(0) {}
  virtual ~I1_i() {}

  void f1() override { p_exit.unlock(); }
  i32 f3() override {
    static i32 v = 0;
    return v++;
  }
  void f2(i32 p1) override {}
  i32 f4(i32 p1) override { return p1 + 1; }
  i32 f5(i32 p1, i32 p2) override { return p1 + p2 + 2; }

private:
  i32 a;
  i32 b;
};

class Wrong_Interface_i : public Wrong_Interface {};

int main(int argc, char *argv[]) {

  DBus::init();
  p_exit.lock();

  Dbus_server server;
  I1_i c;
  server.set_in("/Compo/Server/A", "I1.A", &c);
  server.set_object_name("Compo.Server");
  server.connect();

  // auto t = std::thread(&call_client);

  while (!p_exit.try_lock()) {
    server.step();
  }

  //  t.join();
  server.disconnect();

  return 0;
}

// int main(int argc, char *argv[])
// {
//   DBus::init();

//   Dbus_server server;
//   Wrong_Interface_i c;
//   REQUIRE_THROWS_AS(server.set_in("/a", "I1.a", &c), std::runtime_error);
//   return 0;
// }
