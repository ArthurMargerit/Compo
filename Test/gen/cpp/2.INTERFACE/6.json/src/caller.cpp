#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/Function_json_recv.hpp"
#include "Interfaces/I4Introspection_func/I4Introspection_func.hpp"
#include "Interfaces/I4Introspection_getset/I4Introspection_getset.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IC/IC.hpp"
#include "Interfaces/Return_json_send.hpp"
#include "catch.hpp"
#include <string>

class Function_json_recv_i : public CompoMe::Function_json_recv {
public:
  nlohmann::json &get_params() override { return this->data["params"]; }
  CompoMe::Serialization_context_import ctx;
  nlohmann::json data;

  Function_json_recv_i() : ctx(), data() { this->data["jsonrpc"] = "2.0"; }
  void pull() override {}
  void end() override {}

  std::string get_function() override { return this->data["function"]; }
  void set_id(i32 p_id) { this->data["id"] = p_id; }

  nlohmann::json &get_si() override { return data; }

  CompoMe::Serialization_context_import &get_ctx() override {
    return this->ctx;
  }

  nlohmann::json &get_so() { return this->data; }

  void set_function(std::string f) { this->data["function"] = f; }
};

class Return_json_send_i : public CompoMe::Return_json_send {
public:
  Function_json_recv_i &msg;
  nlohmann::json data;
  CompoMe::Serialization_context_export ctx;
  Return_json_send_i(Function_json_recv_i &r) : msg(r), data() {
    this->data["id"] = this->msg.get_si()["id"];
    this->data["jsonrpc"] = "2.0";
  }
  void start() override {}
  void send() override {}

  CompoMe::Serialization_context_export &get_ctx() override {
    return this->ctx;
  }

  nlohmann::json &get_so() override { return this->data; }
  nlohmann::json &get_si() { return this->data; }
};

class IA_i : public IA {
  i32 a1, a2, a3;

public: //   IA_i() : a1(0), a2(0), a3(0) {}
  virtual ~IA_i() {}
  i32 get_a1() const override { return a1; }
  void set_a1(const i32 &p_a1) override { a1 = p_a1; }
  i32 get_a2() const override { return a2; }
  void set_a2(const i32 &p_a2) override { a2 = p_a2; }
  i32 get_a3() const override { return a3; }
  void set_a3(const i32 &p_a3) override { a3 = p_a3; }
};

class IB_i : public IB {
public:
  IB_i() {}
  virtual ~IB_i() {}

  void f0() {}
  i32 f1() { return 42; }
  i32 f2(i32 p1) { return p1; }
  i32 f3(i32 p1, i32 p2) { return p1 + p2; }
  i32 f4(i32 p1, i32 p2, i32 p3) { return p1 + p2 + p3; }
};

class IC_i : public IC {
public:
  IC_i() {}
  virtual ~IC_i() {}
  S1 f0() override {
    S1 l(4, 9, 16);
    return l;
  }

  void f1(S1 a) override {}

  S1 f2(S1 b) override {
    b.set_a(b.get_a() + 1);
    b.set_b(b.get_b() + 1);
    b.set_c(b.get_c() + 1);
    return b;
  }

  S1 f3(S1 a, S1 b) override {
    S1 c(a.get_a() + b.get_a(), a.get_b() + b.get_b(), a.get_c() + b.get_c());
    return c;
  }
};

class I4Introspection_func_i : public I4Introspection_func {
  void myfunc() override {}
};

class I4Introspection_getset_i : public I4Introspection_getset {
  i32 get_mydata() const override { return 0; }
  void set_mydata(const i32 &) override {}
};

// TEST_CASE("introspection", "[Interface][DBUS][caller]") {
//   I4Introspection_func_i I1;
//   I4Introspection_getset_i I2;

//   SECTION("function") {
//     std::stringstream ss;
//     auto e_c = I1.get_caller_dbus();
//     e_c->introspection(ss);
//     REQUIRE(ss.str() != "");
//     REQUIRE(ss.str().find("myfunc") != std::string::npos);
//   }

//   SECTION("data") {
//     std::stringstream ss;
//     auto e_c = I2.get_caller_dbus();
//     e_c->introspection(ss);
//     REQUIRE(ss.str() != "");
//     REQUIRE(ss.str().find("mydata") != std::string::npos);
//   }
//   e_c->call(fe, re);
// }

TEST_CASE("A caller Interface json", "[Interface][JSON][caller]") {
  IA_i e;

  auto e_c = e.get_caller_json();
  REQUIRE(e_c != nullptr);

  Function_json_recv_i fe;
  Return_json_send_i re(fe);

  fe.set_function("get_a1");
  REQUIRE(e_c->call(fe, re) == true);
  i32 i = -1;
  re.get_si()["result"].get_to(i);
  REQUIRE(i == 0);

  fe.set_function("set_a1");
  fe.get_so()["params"] = nlohmann::json::array({1});
  REQUIRE(e_c->call(fe, re) == true);

  fe.set_function("get_a1");
  REQUIRE(e_c->call(fe, re) == true);
  re.get_si()["result"].get_to(i);
  REQUIRE(i == 1);

  fe.set_function("set_a1");
  fe.get_so()["params"] = nlohmann::json::array({2});
  REQUIRE(e_c->call(fe, re) == true);

  fe.set_function("get_a1");
  REQUIRE(e_c->call(fe, re) == true);
  re.get_si()["result"].get_to(i);
  REQUIRE(i == 2);
}

TEST_CASE("B caller Interface json", "[Interface][json][caller]") {
  IB_i e;

  auto e_c = e.get_caller_json();
  REQUIRE(e_c != nullptr);

  Function_json_recv_i fe;
  Return_json_send_i re(fe);

  {
    fe.set_function("f0");
    REQUIRE(e_c->call(fe, re) == true);
  }

  SECTION("F1 null") {
    fe.set_function("f1");
    fe.get_so()["params"] = nullptr;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 42);
  }
  SECTION("F1 empty object") {
    fe.set_function("f1");
    fe.get_so()["params"] = nlohmann::json::object();
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 42);
  }

  SECTION("F1 empty array ") {
    fe.set_function("f1");
    fe.get_so()["params"] = nlohmann::json::array();
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 42);
  }

  SECTION("F2 object") {
    fe.set_function("f2");
    fe.get_so()["params"]["p1"] = 5;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 5);
  }

  SECTION("F2 array") {
    fe.set_function("f2");
    fe.get_so()["params"] = nlohmann::json::array({0});
    fe.get_so()["params"][0] = 5;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 5);
  }

  SECTION("F3 object") {
    fe.set_function("f3");
    fe.get_so()["params"]["p1"] = (i32)5;
    fe.get_so()["params"]["p2"] = (i32)15;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 15 + 5);
  }

  SECTION("F3 array") {
    fe.set_function("f3");
    fe.get_so()["params"] = nlohmann::json::array({0, 0});
    fe.get_so()["params"][0] = (i32)5;
    fe.get_so()["params"][1] = (i32)15;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 15 + 5);
  }

  SECTION("F4 object") {
    fe.set_function("f4");
    fe.get_so()["params"]["p1"] = (i32)5;
    fe.get_so()["params"]["p2"] = (i32)15;
    fe.get_so()["params"]["p3"] = (i32)25;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 15 + 5 + 25);
  }

  SECTION("F4 array") {
    fe.set_function("f4");
    fe.get_so()["params"] = nlohmann::json::array({nullptr, nullptr, nullptr});
    fe.get_so()["params"][0] = (i32)5;
    fe.get_so()["params"][1] = (i32)15;
    fe.get_so()["params"][2] = (i32)25;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si()["result"].get_to(i);
    REQUIRE(i == 15 + 5 + 25);
  }
}

TEST_CASE("C caller Interface json", "[Interface][JSON][caller]") {
  IC_i e;

  Function_json_recv_i fe;
  Return_json_send_i re(fe);

  auto e_c = e.get_caller_json();
  REQUIRE(e_c != nullptr);

  SECTION("F0 ") {
    fe.set_function("f0");
    CompoMe::Serialization_context_import i;
    S1 s_out;
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_json(re.get_si()["result"], i);
    REQUIRE(s_out.get_a() == 4);
    REQUIRE(s_out.get_b() == 9);
    REQUIRE(s_out.get_c() == 16);
  }

  SECTION("F1 object") {
    fe.set_function("f1");
    CompoMe::Serialization_context_export i;
    S1 s_in;
    s_in.to_json(fe.get_so()["params"]["a"], i);
    REQUIRE(e_c->call(fe, re) == true);
  }

  SECTION("F1 array") {
    fe.set_function("f1");
    CompoMe::Serialization_context_export i;
    S1 s_in;
    fe.get_so()["params"] = nlohmann::json::array({nullptr});
    s_in.to_json(fe.get_so()["params"][0], i);
    REQUIRE(e_c->call(fe, re) == true);
  }

  SECTION("F2 object") {
    fe.set_function("f2");
    S1 s_out, s_in;
    CompoMe::Serialization_context_import i_i;
    CompoMe::Serialization_context_export i_e;
    s_in.to_json(fe.get_so()["params"]["b"], i_e);
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_json(re.get_si()["result"], i_i);

    REQUIRE(s_in.get_a() + 1 == s_out.get_a());
    REQUIRE(s_in.get_b() + 1 == s_out.get_b());
    REQUIRE(s_in.get_c() + 1 == s_out.get_c());
  }

  SECTION("F2 array") {
    fe.set_function("f2");
    S1 s_out, s_in;
    CompoMe::Serialization_context_import i_i;
    CompoMe::Serialization_context_export i_e;
    fe.get_so()["params"] = nlohmann::json::array({nullptr});
    s_in.to_json(fe.get_so()["params"][0], i_e);
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_json(re.get_si()["result"], i_i);

    REQUIRE(s_in.get_a() + 1 == s_out.get_a());
    REQUIRE(s_in.get_b() + 1 == s_out.get_b());
    REQUIRE(s_in.get_c() + 1 == s_out.get_c());
  }

  SECTION("F2 object") {
    fe.set_function("f3");
    S1 s_out, s_in1(1, 2, 3), s_in2(4, 5, 6);
    CompoMe::Serialization_context_import i_i;
    CompoMe::Serialization_context_export i_e;
    s_in1.to_json(fe.get_so()["params"]["a"], i_e);
    s_in2.to_json(fe.get_so()["params"]["b"], i_e);

    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_json(re.get_si()["result"], i_i);

    REQUIRE(s_in1.get_a() + s_in2.get_a() == s_out.get_a());
    REQUIRE(s_in1.get_b() + s_in2.get_b() == s_out.get_b());
    REQUIRE(s_in1.get_c() + s_in2.get_c() == s_out.get_c());
  }

  SECTION("F2 array") {
    fe.set_function("f3");
    S1 s_out, s_in1(1, 2, 3), s_in2(4, 5, 6);
    CompoMe::Serialization_context_import i_i;
    CompoMe::Serialization_context_export i_e;
    fe.get_so()["params"] = nlohmann::json::array({nullptr, nullptr});

    s_in1.to_json(fe.get_so()["params"][0], i_e);
    s_in2.to_json(fe.get_so()["params"][1], i_e);

    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_json(re.get_si()["result"], i_i);

    REQUIRE(s_in1.get_a() + s_in2.get_a() == s_out.get_a());
    REQUIRE(s_in1.get_b() + s_in2.get_b() == s_out.get_b());
    REQUIRE(s_in1.get_c() + s_in2.get_c() == s_out.get_c());
  }
}
