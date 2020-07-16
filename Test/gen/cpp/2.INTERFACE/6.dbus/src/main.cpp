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
  DBus::CallMessage::pointer p;
  DBus::MessageAppendIterator it;

  Function_dbus_send_i() {}
  virtual ~Function_dbus_send_i() {}

public:

  void start() override {
    p = DBus::CallMessage::create();
  }
  void send() override {}

  void set_function(std::string str) override {
    this->p->set_member(str);
    return;
  }

  DBus::MessageAppendIterator &get_so() override {
    this->it = p->append();
    return this->it;
  }
};

class Return_dbus_recv_i : public CompoMe::Return_dbus_recv {
  Function_dbus_send_i& _p;
  DBus::ReturnMessage::pointer p;
  DBus::MessageIterator it;

public:
  Return_dbus_recv_i(Function_dbus_send_i& r) : _p(r) {}
  virtual ~Return_dbus_recv_i() {}

public:
  void pull() override {
    this->p = this->_p.p->create_reply();
    i32 a = 0;
    this->p->append() << a;
  }

  void end() override {}

  DBus::MessageIterator &get_si() override {
    this->it = p->begin();
    return this->it;
  }
};

// class Ib_imp : public IB
// {
// public:
//   Ib_imp(){}
//   virtual ~Ib_imp(){}
//   void f0 () override {}
//   int f1 () override { return 0;}
//   int f2 (int p1) override { return 0;}
//   int f3 (int p1,int p2) override { return 0;}
//   int f4 (int p1,int p2,int p3) override { return 0;}
// };
TEST_CASE("Empty Interface dbus", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<Empty> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE( r.connected());
}

TEST_CASE("IA Interface dbus get/set", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IA> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE( r.connected());

  r->get_a1();
  REQUIRE(l_s.p->member() == std::string("get_a1"));
  REQUIRE(l_s.p->signature() == std::string(""));

  r->get_a2();
  REQUIRE(l_s.p->member() == std::string("get_a2"));
  REQUIRE(l_s.p->signature() == std::string(""));

  r->get_a3();
  REQUIRE(l_s.p->member() == std::string("get_a3"));
  REQUIRE(l_s.p->signature() == std::string(""));

  r->set_a1(1);
  REQUIRE(l_s.p->member() == std::string("set_a1"));
  REQUIRE(l_s.p->signature() == std::string("i"));

  r->set_a2(2);
  REQUIRE(l_s.p->member() == std::string("set_a2"));
  REQUIRE(l_s.p->signature() == std::string("i"));

  r->set_a3(3);
  REQUIRE(l_s.p->member() == std::string("set_a3"));
  REQUIRE(l_s.p->signature() == std::string("i"));
}

TEST_CASE("IB Interface dbus functionx", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IB> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE( r.connected());

  r->f0();
  CHECK(l_s.p->member() == std::string("f0"));

  r->f1();
  CHECK(l_s.p->member() == std::string("f1"));

  r->f2(1);
  CHECK(l_s.p->member() == std::string("f2"));
  CHECK(l_s.p->signature() == std::string("i"));
  auto i = l_s.p->begin();
  i32 v_i=0;
  i >> v_i;
  CHECK(v_i == 1);

  r->f3(1,2);
  CHECK(l_s.p->member() == std::string("f3"));
  CHECK(l_s.p->signature() == std::string("ii"));
  i = l_s.p->begin();
  i >> v_i;
  CHECK(v_i == 1);
  i >> v_i;
  CHECK(v_i == 2);

  r->f4(1,2,3);
  CHECK(l_s.p->member() == std::string("f4"));
  CHECK(l_s.p->signature() == std::string("iii"));
  i = l_s.p->begin();
  i >> v_i;
  CHECK(v_i == 1);
  i >> v_i;
  CHECK(v_i == 2);
  i >> v_i;
  CHECK(v_i == 3);
}

TEST_CASE("IC Interface dbus function", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IC> r;

  Function_dbus_send_i l_s;
  Return_dbus_recv_i l_r(l_s);

  auto p = r.fake_dbus_it(l_s, l_r);

  REQUIRE(p != nullptr);
  REQUIRE( r.connected());

  auto a = r->f0();
  CHECK(l_s.p->member() == std::string("f0"));

  S1 s1;
  r->f1(s1);
  CHECK(l_s.p->member() == std::string("f1"));
  CHECK(l_s.p->signature() == std::string("a{sv}"));

  S1 s2;
  auto b = r->f2(s2);
  CHECK(l_s.p->member() == std::string("f2"));
  CHECK(l_s.p->signature() == std::string("a{sv}"));
}
