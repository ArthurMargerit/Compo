#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IC/IC.hpp"
#include "catch.hpp"

#include "Interfaces/Function_dbus_recv.hpp"
#include "Interfaces/Return_dbus_send.hpp"

class Function_dbus_recv_i : public Function_dbus_recv {
  Serialization_context_import ctx;

  DBus::MessageIterator _it;
  std::string _f;
  DBus::MessageAppendIterator _a_it;
  bool r;
  bool r1;

public:
  DBus::CallMessage::pointer mc;

  void pull() override {}

  void end() override {}

  std::string get_function() override { return this->_f; }

  DBus::MessageIterator &get_si() {
    if (this->r == true) {
      this->_it = this->mc->begin();
      this->r = false;
    }

    return _it;
  }

  Serialization_context_import &get_ctx() override { return this->ctx; }

  DBus::MessageAppendIterator &get_so() {
    if (this->r1 == true) {
      this->_a_it = this->mc->append();
      this->r1 = false;
    }

    return _a_it;
  }

  void set_function(std::string f) { this->_f = f; }

  void reset() {
    this->mc = DBus::CallMessage::create();
    this->r = true;
    this->r1 = true;
  }
};

class Return_dbus_send_i : public Return_dbus_send {
  DBus::MessageAppendIterator _a_it;
  DBus::MessageIterator _it;
  bool r;

  Serialization_context_export ctx;
  Function_dbus_recv_i &msg;
  DBus::ReturnMessage::pointer ret;

public:
  Return_dbus_send_i(Function_dbus_recv_i &f) : msg(f) {}
  void start() override {}
  void send() override {}

  DBus::MessageAppendIterator &get_so() override {
    this->_a_it = this->ret->append();
    return _a_it;
  }

  Serialization_context_export &get_ctx() override { return ctx; }

  DBus::MessageIterator &get_si() {
    if (this->r) {
      this->_it = this->ret->begin();
      this->r = false;
    }

    return _it;
  }

  void reset() {
    this->ret = this->msg.mc->create_reply();
    this->r = true;
  }
};

class IA_i : public IA {
  i32 a1, a2, a3;

public:
  IA_i() : a1(0), a2(0), a3(0) {}
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
  i32 f3(i32 p1, i32 p2) {
    std::cout << ">" << p1 << "," << p2 << "<\n";
    return p1 + p2;
  }
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
    std::cout << a.get_a() << "|" << b.get_a() << "\n";
    S1 c(a.get_a() + b.get_a(), a.get_b() + b.get_b(), a.get_c() + b.get_c());
    return c;
  }
};

TEST_CASE("Empty caller Interface dbus", "[Interface][DBUS][caller]") {
  Empty e;
  Function_dbus_recv_i fe;
  Return_dbus_send_i re(fe);
  auto e_c = e.get_caller_dbus();
  e_c->introspection(std::cout);
  //  e_c->call(fe, re);
}

TEST_CASE("A caller Interface dbus", "[Interface][DBUS][caller]") {
  IA_i e;
  auto e_c = e.get_caller_dbus();
  e_c->introspection(std::cout);

  Function_dbus_recv_i fe;
  Return_dbus_send_i re(fe);

  fe.reset();
  re.reset();

  fe.set_function("get_a1");
  e_c->call(fe, re);
  i32 i = -1;
  re.get_si() >> i;
  REQUIRE(i == 0);

  fe.reset();
  re.reset();

  fe.set_function("set_a1");
  fe.get_so() << 1;
  e_c->call(fe, re);

  fe.reset();
  re.reset();
  fe.set_function("get_a1");
  e_c->call(fe, re);
  re.get_si() >> i;
  REQUIRE(i == 1);

  fe.reset();
  re.reset();
  fe.set_function("set_a1");
  fe.get_so() << 2;
  e_c->call(fe, re);

  fe.reset();
  re.reset();
  fe.set_function("get_a1");
  e_c->call(fe, re);
  re.get_si() >> i;
  REQUIRE(i == 2);
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
    Serialization_context_import i;
    S1 s_out;
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_stream(re.get_si(), i);

    REQUIRE(s_out.get_a() == 4);
    REQUIRE(s_out.get_b() == 9);
    REQUIRE(s_out.get_c() == 16);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f1");
    Serialization_context_export i;
    S1 s_in;
    s_in.to_stream(fe.get_so(), i);
    REQUIRE(e_c->call(fe, re) == true);
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f2");
    S1 s_out, s_in;
    Serialization_context_import i_i;
    Serialization_context_export i_e;
    s_in.to_stream(fe.get_so(), i_e);
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_stream(re.get_si(), i_i);

    REQUIRE(s_in.get_a() + 1 == s_out.get_a());
    REQUIRE(s_in.get_b() + 1 == s_out.get_b());
    REQUIRE(s_in.get_c() + 1 == s_out.get_c());
  }

  {
    fe.reset();
    re.reset();
    fe.set_function("f3");
    S1 s_out, s_in1(1, 2, 3), s_in2(4, 5, 6);
    Serialization_context_import i_i;
    Serialization_context_export i_e;
    auto i = fe.get_so();
    i = s_in2.to_stream(i, i_e);
    i = s_in1.to_stream(i, i_e);
    REQUIRE(e_c->call(fe, re) == true);
    s_out.from_stream(re.get_si(), i_i);

    std::cout << "o" << fe.mc->signature() << "o"
              << "\n";

    REQUIRE(s_in1.get_a() + s_in2.get_a() == s_out.get_a());
    REQUIRE(s_in1.get_b() + s_in2.get_b() == s_out.get_b());
    REQUIRE(s_in1.get_c() + s_in2.get_c() == s_out.get_c());
  }
}
