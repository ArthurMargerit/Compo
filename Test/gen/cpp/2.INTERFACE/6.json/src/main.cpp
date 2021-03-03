#include "Components/Require_helper.hpp"

#include "Interfaces/Empty/Empty.hpp"

// #include "Interfaces/Function_dbus_send.hpp"
#include "Interfaces/Function_json_send.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IC/IC.hpp"
#include "Interfaces/Return_json_recv.hpp"
#include "Structs/S1.hpp"
#include "catch.hpp"
#include <functional>

class Function_json_send_i;

class Return_json_recv_i : public CompoMe::Return_json_recv {
public:
  Function_json_send_i &_p;
  std::function<void(Return_json_recv_i &d)> func;

  Return_json_recv_i(Function_json_send_i &r) : _p(r) {
    this->get_data()["jsonrpc"] = "2.0";
  }
  virtual ~Return_json_recv_i() {}

  void pull() override { this->func(*this); }
  void end() override {}
  void clean();
};

class Function_json_send_i : public CompoMe::Function_json_send {
public:
  Return_json_recv_i ret;

  Function_json_send_i() : ret(*this) { this->get_data()["jsonrpc"] = "2.0"; }
  virtual ~Function_json_send_i() {}
  void start() override {}
  void send() override {}
};

#include <iostream>
TEST_CASE("IA Interface json get/set", "[Interface][JSON]") {

  CompoMe::Require_helper_t<IA> r;
  Function_json_send_i l_s;
  l_s.ret.func = [](Return_json_recv_i &ret) { ret.get_data()["result"] = 0; };

  auto p = r.fake_json_it(l_s, l_s.ret);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  SECTION("set a1") {
    r->set_a1(1);
    REQUIRE(l_s.get_data()["function"] == "set_a1");
    REQUIRE(l_s.get_data()["params"][0] == 1);
  }

  SECTION("set a2") {
    r->set_a2(2);
    REQUIRE(l_s.get_data()["function"] == "set_a2");
    REQUIRE(l_s.get_data()["params"][0] == 2);
  }

  SECTION("set a3") {
    r->set_a3(3);
    REQUIRE(l_s.get_data()["function"] == "set_a3");
    REQUIRE(l_s.get_data()["params"][0] == 3);
  }

  SECTION("get a1") {
    r->get_a1();
    REQUIRE(l_s.get_data()["function"] == "get_a1");
    REQUIRE(l_s.get_data()["params"].size() == 0);
  }

  SECTION("get a2") {
    r->get_a2();
    REQUIRE(l_s.get_data()["function"] == "get_a2");
    REQUIRE(l_s.get_data()["params"].size() == 0);
  }

  SECTION("get a3") {
    r->get_a3();
    REQUIRE(l_s.get_data()["function"] == "get_a3");
    REQUIRE(l_s.get_data()["params"].size() == 0);
  }
}

TEST_CASE("IB Interface dbus functionx", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IB> r;
  Function_json_send_i l_s;
  l_s.ret.func = [](Return_json_recv_i &ret) {
    if (ret._p.get_data()["function"] != "f0") {
      ret.get_data()["result"] = 0;
    }
  };

  auto p = r.fake_json_it(l_s, l_s.ret);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  r->f0();
  CHECK(l_s.get_data()["function"] == "f0");

  r->f1();
  CHECK(l_s.get_data()["function"] == "f1");
  CHECK(l_s.get_data()["params"].size() == 0);

  r->f2(1);
  CHECK(l_s.get_data()["function"] == "f2");
  CHECK(l_s.get_data()["params"].size() == 1);

  r->f3(1, 2);
  CHECK(l_s.get_data()["function"] == "f3");
  CHECK(l_s.get_data()["params"].size() == 2);

  r->f4(1, 2, 3);
  CHECK(l_s.get_data()["function"] == "f4");
  CHECK(l_s.get_data()["params"].size() == 3);
}

TEST_CASE("IC Interface dbus function", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IC> r;
  Function_json_send_i l_s;
  auto p = r.fake_json_it(l_s, l_s.ret);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  l_s.ret.func = [](Return_json_recv_i &ret) {
    CompoMe::Serialization_context_export ctx;
    S1 s;
    s.set_a(1);
    s.set_b(2);
    s.set_c(3);

    s.to_json(ret.get_data()["result"], ctx);
  };

  SECTION("f0") {
    auto a = r->f0();
    REQUIRE(a.get_a() == 1);
    REQUIRE(a.get_b() == 2);
    REQUIRE(a.get_c() == 3);

    CHECK(l_s.get_data()["function"] == "f0");
    CHECK(l_s.get_data()["params"].size() == 0);
    CHECK(l_s.ret.get_data()["result"]["type"] == "S1");
  }

  SECTION("f2") {
    S1 s;
    auto a = r->f2(s);
    REQUIRE(a.get_a() == 1);
    REQUIRE(a.get_b() == 2);
    REQUIRE(a.get_c() == 3);

    CHECK(l_s.get_data()["function"] == "f2");
    CHECK(l_s.get_data()["params"].size() == 1);
    CHECK(l_s.ret.get_data()["result"]["type"] == "S1");
  }

  SECTION("f3") {
    S1 s1, s2;
    auto a = r->f3(s1, s2);
    REQUIRE(a.get_a() == 1);
    REQUIRE(a.get_b() == 2);
    REQUIRE(a.get_c() == 3);

    CHECK(l_s.get_data()["function"] == "f3");
    CHECK(l_s.get_data()["params"].size() == 2);
    CHECK(l_s.ret.get_data()["result"]["type"] == "S1");
  }
}
