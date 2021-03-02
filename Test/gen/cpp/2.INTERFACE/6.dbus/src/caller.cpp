#include "I.hpp"
#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/Function_dbus_recv.hpp"
#include "Interfaces/Return_dbus_send.hpp"
#include "catch.hpp"
#include <iostream>

class Function_dbus_recv_i;

class Return_dbus_send_i : public CompoMe::Return_dbus_send {
  Function_dbus_recv_i &msg;

  DBusMessage *ret;
  DBusMessageIter _a_it;
  DBusMessageIter _it;

  CompoMe::Serialization_context_export ctx;

public:
  Return_dbus_send_i(Function_dbus_recv_i &f) : msg(f), ret(nullptr), ctx() {}
  void start() override {}
  void send() override {}

  DBusMessageIter &get_so() override { return _a_it; }

  DBusMessageIter &get_si() {
    dbus_message_iter_init(this->ret, &this->_it);
    return _it;
  }
  CompoMe::Serialization_context_export &get_ctx() override { return ctx; }

  void reset();
};

class Function_dbus_recv_i : public CompoMe::Function_dbus_recv {
  DBusMessageIter _it;
  DBusMessageIter _a_it;

  CompoMe::Serialization_context_import ctx;

  std::string _f;

  Return_dbus_send_i ret;
  bool b;

public:
  DBusMessage *mc;

  Function_dbus_recv_i();

  void pull() override { this->reset(); }
  void end() override {}
  Return_dbus_send_i &get_re() { return this->ret; }

  std::string get_function() override {
    return dbus_message_get_member(this->mc);
  }

  DBusMessageIter &get_si() override {
    if (this->b) {
      dbus_message_iter_init(this->mc, &this->_it);
      this->b = false;
    }
    return _it;
  }

  CompoMe::Serialization_context_import &get_ctx() override {
    return this->ctx;
  }

  DBusMessageIter &get_so() { return _a_it; }

  void set_function(std::string f) {
    dbus_message_set_member(this->mc, f.c_str());
  }

  void reset() {
    if (this->mc != nullptr) {
      dbus_message_unref(this->mc);
      this->mc = nullptr;
    }
    this->mc = dbus_message_new_method_call("test.method.server1",
                                            "/test/method/Object2",
                                            "test.method.Type2", "unset");
    dbus_message_set_serial(this->mc, 1);
    this->b = true;
    dbus_message_iter_init_append(this->mc, &this->_a_it);
    this->ret.reset();
  }
};

Function_dbus_recv_i::Function_dbus_recv_i() : ret(*this), mc(nullptr) {
  this->reset();
}

void Return_dbus_send_i::reset() {
  if (this->ret != nullptr) {
    dbus_message_unref(this->ret);
    this->ret = nullptr;
  }

  this->ret = dbus_message_new_method_return(this->msg.mc);
  dbus_message_iter_init_append(this->ret, &this->_a_it);
}

TEST_CASE("introspection", "[Interface][DBUS][caller]") {
  I4Introspection_func_i I1;
  I4Introspection_getset_i I2;

  SECTION("function") {
    std::stringstream ss;
    auto e_c = I1.get_caller_dbus();
    e_c->introspection(ss);
    REQUIRE(ss.str() != "");
    REQUIRE(ss.str().find("myfunc") != std::string::npos);
  }

  SECTION("data") {
    std::stringstream ss;
    auto e_c = I2.get_caller_dbus();
    e_c->introspection(ss);
    REQUIRE(ss.str() != "");
    REQUIRE(ss.str().find("mydata") != std::string::npos);
  }
}

TEST_CASE("A caller Interface dbus", "[Interface][DBUS][caller]") {
  IA_i e;
  auto e_c = e.get_caller_dbus();
  {
    Function_dbus_recv_i fe;
    Return_dbus_send_i &re = fe.get_re();

    fe.set_function("test");
    REQUIRE(fe.get_function() == "test");
  }

  {
    Function_dbus_recv_i fe;
    Return_dbus_send_i &re = fe.get_re();

    fe.set_function("get_a1");
    CHECK(true == e_c->call(fe, re));

    i32 i = -1;
    re.get_si() >> i;
    CHECK(i == 0);
  }

  {
    Function_dbus_recv_i fe;
    Return_dbus_send_i &re = fe.get_re();

    fe.set_function("set_a1");
    fe.get_so() << 1;
    CHECK(e_c->call(fe, re) == true);
    CHECK(e.get_a1() == 1);
  }

  {
    Function_dbus_recv_i fe;
    Return_dbus_send_i &re = fe.get_re();

    fe.set_function("get_a1");
    CHECK(e_c->call(fe, re) == true);
    i32 i = -1;
    re.get_si() >> i;
    CHECK(i == 1);
  }

  {
    Function_dbus_recv_i fe;
    Return_dbus_send_i &re = fe.get_re();

    fe.set_function("set_a1");
    fe.get_so() << 2;
    CHECK(e_c->call(fe, re) == true);
    CHECK(e.get_a1() == 2);
  }

  {
    Function_dbus_recv_i fe;
    Return_dbus_send_i &re = fe.get_re();

    fe.set_function("get_a1");
    CHECK(e_c->call(fe, re) == true);
    i32 i = -1;
    re.get_si() >> i;
    CHECK(i == 2);
  }
}

TEST_CASE("B caller Interface dbus", "[Interface][DBUS][caller]") {
  IB_i e;
  auto e_c = e.get_caller_dbus();
  e_c->introspection(std::cout);

  Function_dbus_recv_i fe;
  Return_dbus_send_i re(fe);

  {
    fe.reset();
    re.reset();
    fe.set_function("f0");
    REQUIRE(e_c->call(fe, re) == true);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f1");
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si() >> i;
    REQUIRE(i == 42);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f2");
    fe.get_so() << (i32)5;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si() >> i;
    REQUIRE(i == 5);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f3");
    fe.get_so() << (i32)5;
    fe.get_so() << (i32)15;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si() >> i;
    REQUIRE(i == 15 + 5);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f4");
    fe.get_so() << (i32)5;
    fe.get_so() << (i32)15;
    fe.get_so() << (i32)25;
    REQUIRE(e_c->call(fe, re) == true);
    i32 i = 0;
    re.get_si() >> i;
    REQUIRE(i == 15 + 5 + 25);
  }
}

TEST_CASE("C caller Interface dbus", "[Interface][DBUS][caller]") {
  IC_i e;
  Function_dbus_recv_i fe;
  Return_dbus_send_i re(fe);
  auto e_c = e.get_caller_dbus();
  e_c->introspection(std::cout);

  {
    fe.reset();
    re.reset();
    fe.set_function("f0");
    CompoMe::Serialization_context_import i;
    S1 s_out;
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_dbus(re.get_si(), i);

    REQUIRE(s_out.get_a() == 4);
    REQUIRE(s_out.get_b() == 9);
    REQUIRE(s_out.get_c() == 16);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f1");
    CompoMe::Serialization_context_export i;
    S1 s_in;
    s_in.to_dbus(fe.get_so(), i);
    REQUIRE(e_c->call(fe, re) == true);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f2");
    S1 s_out, s_in;
    CompoMe::Serialization_context_import i_i;
    CompoMe::Serialization_context_export i_e;
    s_in.to_dbus(fe.get_so(), i_e);
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_dbus(re.get_si(), i_i);

    REQUIRE(s_in.get_a() + 1 == s_out.get_a());
    REQUIRE(s_in.get_b() + 1 == s_out.get_b());
    REQUIRE(s_in.get_c() + 1 == s_out.get_c());
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f3");
    S1 s_out, s_in1(1, 2, 3), s_in2(4, 5, 6);
    CompoMe::Serialization_context_import i_i;
    CompoMe::Serialization_context_export i_e;
    auto i = fe.get_so();
    s_in2.to_dbus(i, i_e);
    s_in1.to_dbus(i, i_e);
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_dbus(re.get_si(), i_i);

    REQUIRE(s_in1.get_a() + s_in2.get_a() == s_out.get_a());
    REQUIRE(s_in1.get_b() + s_in2.get_b() == s_out.get_b());
    REQUIRE(s_in1.get_c() + s_in2.get_c() == s_out.get_c());
  }
}
