#include "Components/Require_helper.hpp"
#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/Function_dbus_send.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IC/IC.hpp"
#include "Interfaces/Return_dbus_recv.hpp"
#include "Structs/S1.hpp"
#include "catch.hpp"

#include <functional>

class Function_dbus_send_i;

class Return_dbus_recv_i : public CompoMe::Return_dbus_recv {
public:
  Function_dbus_send_i &_p;
  DBusMessage *p;
  DBusMessageIter _a_it;
  DBusMessageIter _it;
  std::function<void(Return_dbus_recv_i &ret, DBusMessageIter &_a_it)> f_t;

  Return_dbus_recv_i(Function_dbus_send_i &r) : _p(r), p(nullptr) {}
  virtual ~Return_dbus_recv_i() {}

  void pull() override;
  void end() override;
  void clean();

  std::string signature() {
    return std::string(dbus_message_get_signature(this->p));
  }
  DBusMessageIter &get_si() override {
    dbus_message_iter_init(this->p, &this->_it);
    return this->_it;
  }
};

class Function_dbus_send_i : public CompoMe::Function_dbus_send {

public:
  Return_dbus_recv_i ret;

  DBusMessage *p;
  DBusMessageIter _a_it;

  Function_dbus_send_i() : ret(*this), p(nullptr) {}
  virtual ~Function_dbus_send_i() {}

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

  std::string member() { return std::string(dbus_message_get_member(this->p)); }

  std::string signature() {
    return std::string(dbus_message_get_signature(this->p));
  }

  DBusMessageIter &get_so() override {
    dbus_message_iter_init_append(this->p, &this->_a_it);
    return this->_a_it;
  }
};

void Return_dbus_recv_i::pull() {
  this->p = dbus_message_new_method_return(this->_p.p);
  dbus_message_iter_init_append(this->p, &this->_a_it);

  this->f_t(*this, this->_a_it);
}

void Return_dbus_recv_i::end() {}
void Return_dbus_recv_i::clean() {
  if (this->p != nullptr) {
    dbus_message_unref(this->p);
    this->p = nullptr;
  }
  if (this->_p.p != nullptr) {
    dbus_message_unref(this->_p.p);
    this->_p.p = nullptr;
  }
}

// TEST_CASE("Empty Interface dbus", "[Interface][DBUS]") {

//   CompoMe::Require_helper_t<Empty> r;

//   Function_dbus_send_i l_s;
//   Return_dbus_recv_i l_r(l_s);

//   auto p = r.fake_dbus_it(l_s, l_r);

//   REQUIRE(p != nullptr);
//   REQUIRE(r.connected());
// }

TEST_CASE("IA Interface dbus get/set", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IA> r;
  Function_dbus_send_i l_s;
  auto p = r.fake_dbus_it(l_s, l_s.ret);

  l_s.ret.f_t = [](Return_dbus_recv_i &ret, DBusMessageIter &_a_it) {
    CompoMe::Serialization_context_export ctx;
    if (ret._p.member().find("get") != std::string::npos) {
      i32 i;
      _a_it << i;
    }
  };

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  r->set_a1(1);
  REQUIRE(l_s.member() == std::string("set_a1"));
  REQUIRE(l_s.signature() == std::string("i"));
  REQUIRE(l_s.ret.signature() == std::string(""));
  l_s.ret.clean();

  r->set_a2(2);
  REQUIRE(l_s.member() == std::string("set_a2"));
  REQUIRE(l_s.signature() == std::string("i"));
  REQUIRE(l_s.ret.signature() == std::string(""));
  l_s.ret.clean();

  r->set_a3(3);
  REQUIRE(l_s.member() == std::string("set_a3"));
  REQUIRE(l_s.signature() == std::string("i"));
  REQUIRE(l_s.ret.signature() == std::string(""));
  l_s.ret.clean();

  r->get_a1();
  REQUIRE(l_s.member() == std::string("get_a1"));
  REQUIRE(l_s.signature() == std::string(""));
  REQUIRE(l_s.ret.signature() == std::string("i"));
  l_s.ret.clean();

  r->get_a2();
  REQUIRE(l_s.member() == std::string("get_a2"));
  REQUIRE(l_s.signature() == std::string(""));
  REQUIRE(l_s.ret.signature() == std::string("i"));
  l_s.ret.clean();

  r->get_a3();
  REQUIRE(l_s.member() == std::string("get_a3"));
  REQUIRE(l_s.signature() == std::string(""));
  REQUIRE(l_s.ret.signature() == std::string("i"));
  l_s.ret.clean();
}

TEST_CASE("IB Interface dbus functionx", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IB> r;
  Function_dbus_send_i l_s;
  l_s.ret.f_t = [](Return_dbus_recv_i &ret, DBusMessageIter &_a_it) {
    CompoMe::Serialization_context_export ctx;
    if (ret._p.member() != "f0") {
      i32 i;
      _a_it << i;
    }
  };

  auto p = r.fake_dbus_it(l_s, l_s.ret);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  r->f0();
  CHECK(l_s.member() == std::string("f0"));

  r->f1();
  CHECK(l_s.member() == std::string("f1"));

  r->f2(1);
  CHECK(l_s.member() == std::string("f2"));
  CHECK(l_s.signature() == std::string("i"));

  r->f3(1, 2);
  CHECK(l_s.member() == std::string("f3"));
  CHECK(l_s.signature() == std::string("ii"));

  r->f4(1, 2, 3);
  CHECK(l_s.member() == std::string("f4"));
  CHECK(l_s.signature() == std::string("iii"));
}

TEST_CASE("IC Interface dbus function", "[Interface][DBUS]") {

  CompoMe::Require_helper_t<IC> r;
  Function_dbus_send_i l_s;
  auto p = r.fake_dbus_it(l_s, l_s.ret);

  REQUIRE(p != nullptr);
  REQUIRE(r.connected());

  l_s.ret.f_t = [](Return_dbus_recv_i &ret, DBusMessageIter &_a_it) {
    CompoMe::Serialization_context_export ctx;
    S1 s;
    s.to_stream(_a_it, ctx);
  };

  {
    auto a = r->f0();
    CHECK(l_s.member() == std::string("f0"));
    l_s.ret.clean();
  }
  {
    S1 s;
    auto a = r->f2(s);
    CHECK(l_s.member() == std::string("f2"));
    CHECK(l_s.signature() == std::string("a{sv}"));
    l_s.ret.clean();
  }
  {
    S1 s1, s2;
    auto a = r->f3(s1, s2);
    CHECK(l_s.member() == std::string("f3"));
    CHECK(l_s.signature() == std::string("a{sv}a{sv}"));
    l_s.ret.clean();
  }
}
