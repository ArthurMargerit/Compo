#include "catch.hpp"

#include "Components/Require_helper.hpp"

#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IC/IC.hpp"

#include "Interfaces/Function_dbus_send.hpp"
#include "Interfaces/Return_dbus_recv.hpp"

class Function_dbus_send_i : public CompoMe::Function_dbus_send {

public:
  DBusMessage *p;
  DBusMessageIter it;

  Function_dbus_send_i() : p(nullptr) {}
  virtual ~Function_dbus_send_i() {}

public:
  void start() override {
    p = dbus_message_new_method_call("test.method.server",
                                     "/test/method/Object", "test.method.Type",
                                     "Method");
    // to avoid waring and fail
    dbus_message_set_serial(this->p, 1);
  }

  void send() override {}

  void set_function(std::string str) override {
    dbus_message_set_member(this->p, str.c_str());
    return;
  }

  std::string member() {
    const char *s = dbus_message_get_member(this->p);
    return std::string(s);
  }

  std::string signature() {
    const char *s = dbus_message_get_signature(this->p);
    return std::string(s);
  }

  DBusMessageIter &get_so() override {
    dbus_message_iter_init_append(this->p, &this->it);
    return this->it;
  }
};

class Return_dbus_recv_i : public CompoMe::Return_dbus_recv {
  Function_dbus_send_i &_p;
  DBusMessage *p;
  DBusMessageIter it;

public:
  Return_dbus_recv_i(Function_dbus_send_i &r) : _p(r), p(nullptr) {}
  virtual ~Return_dbus_recv_i() {}

public:
  void pull() override {
    this->p = dbus_message_new_method_return(this->_p.p);

    i32 a = 0;
    dbus_message_iter_append_basic(&this->get_si(), DBUS_TYPE_INT32, &a);
  }

  void end() override {
    if (this->p != nullptr) {
      dbus_message_unref(this->p);
      this->p = nullptr;
    }
    if (this->_p.p != nullptr) {
      dbus_message_unref(this->_p.p);
      this->_p.p = nullptr;
    }
  }

  DBusMessageIter &get_si() override {
    dbus_message_iter_init(this->p, &this->it);
    return this->it;
  }
};

TEST_CASE("Empty Interface dbus", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<Empty> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());
}

TEST_CASE("IA Interface dbus get/set", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IA> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  r->get_a1();
  REQUIRE(l_s.member() == std::string("get_a1"));
  REQUIRE(l_s.signature() == std::string(""));

  r->get_a2();
  REQUIRE(l_s.member() == std::string("get_a2"));
  REQUIRE(l_s.signature() == std::string(""));

  r->get_a3();
  REQUIRE(l_s.member() == std::string("get_a3"));
  REQUIRE(l_s.signature() == std::string(""));

  r->set_a1(1);
  REQUIRE(l_s.member() == std::string("set_a1"));
  REQUIRE(l_s.signature() == std::string("i"));

  r->set_a2(2);
  REQUIRE(l_s.member() == std::string("set_a2"));
  REQUIRE(l_s.signature() == std::string("i"));

  r->set_a3(3);
  REQUIRE(l_s.member() == std::string("set_a3"));
  REQUIRE(l_s.signature() == std::string("i"));
}

TEST_CASE("IB Interface dbus functionx", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IB> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  r->f0();
  CHECK(l_s.member() == std::string("f0"));

  r->f1();
  CHECK(l_s.member() == std::string("f1"));

  r->f2(1);
  CHECK(l_s.member() == std::string("f2"));
  CHECK(l_s.signature() == std::string("i"));
  // auto i = l_s.p->begin();
  // i32 v_i = 0;
  // i >> v_i;
  // CHECK(v_i == 1);

  r->f3(1, 2);
  CHECK(l_s.member() == std::string("f3"));
  CHECK(l_s.signature() == std::string("ii"));
  // i = l_s.p->begin();
  // i >> v_i;
  // CHECK(v_i == 1);
  // i >> v_i;
  // CHECK(v_i == 2);

  r->f4(1, 2, 3);
  CHECK(l_s.member() == std::string("f4"));
  CHECK(l_s.signature() == std::string("iii"));
  // i = l_s.p->begin();
  // i >> v_i;
  // CHECK(v_i == 1);
  // i >> v_i;
  // CHECK(v_i == 2);
  // i >> v_i;
  // CHECK(v_i == 3);
}

TEST_CASE("IC Interface dbus function", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IC> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  auto a = r->f0();
  CHECK(l_s.member() == std::string("f0"));

  S1 s1;
  r->f1(s1);
  CHECK(l_s.member() == std::string("f1"));
  CHECK(l_s.signature() == std::string("a{sv}"));

  S1 s2;
  auto b = r->f2(s2);
  CHECK(l_s.member() == std::string("f2"));
  CHECK(l_s.signature() == std::string("a{sv}"));
}
