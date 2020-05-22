#include "catch.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

#include "Interfaces/Empty/Empty.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IA/IA_caller.hpp"
#include "Interfaces/IA/IA_fake.hpp"

#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IB/IB_caller.hpp"
#include "Interfaces/IB/IB_fake.hpp"

#include "Interfaces/IC/IC.hpp"
#include "Interfaces/IC/IC_caller.hpp"
#include "Interfaces/IC/IC_fake.hpp"

#include "Interfaces/ID/ID.hpp"
#include "Interfaces/ID/ID_caller.hpp"
#include "Interfaces/ID/ID_fake.hpp"

#include "Interfaces/IE/IE.hpp"
#include "Interfaces/IE/IE_caller.hpp"
#include "Interfaces/IE/IE_fake.hpp"

// basic String convertion ////////////////////////////////////////////////////
class Function_string_stream_send : public Function_stream_send {
public:
  std::ostream &_os;
  Function_string_stream_send(std::ostream &os) : _os(os) {}
  void start() override {}
  void send() override {}
  std::ostream &get_so() override { return this->_os; }
};

class Return_string_stream_recv : public Return_stream_recv {
public:
  std::istream &_is;
  Return_string_stream_recv(std::istream &is) : _is(is) {}
  void pull() override {}
  void end() override {}
  std::istream &get_si() override { return this->_is; }
};

class Return_string_stream_send : public Return_stream_send {
public:
  std::ostream &_os;
  Return_string_stream_send(std::ostream &os) : _os(os) {}
  void start() override {}
  void send() override {}
  std::ostream &get_so() override { return this->_os; }
};

class Function_string_stream_recv : public Function_stream_recv {
public:
  std::istream &_is;
  Function_string_stream_recv(std::istream &is) : _is(is) {}
  void pull() override {}
  void end() override {}
  std::istream &get_si() override { return this->_is; }
};

class IB_test : public IB {
public:
  IB_test() {}
  virtual ~IB_test() {}

  void f0() override { return; }
  int f1() override { return 1; }
  int f2(int p1) override { return p1 + 1; }
  int f3(int p1, int p2) override { return p1 + p2; }
  int f4(int p1, int p2, int p3) override { return p1 + p2 + p3; }
};

class IA_test : public IA {
  int a1;
  int a2;
  int a3;

public:
  int get_a1() const override { return a1; }

  void set_a1(const int &a1) override { this->a1 = a1; }

  int get_a2() const override { return a2; }

  void set_a2(const int &a2) override { this->a2 = a2; }

  int get_a3() const override { return a3; }

  void set_a3(const int &a3) override { this->a3 = a3; }

  IA_test() {}
  virtual ~IA_test() {}
};

TEST_CASE("Interfaces Call simple get/set", "[Interface][Call][Get/Set]") {
  IA_test ia_t;
  IA_caller ia_c(ia_t);
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_recv fs_c(so);
  Return_string_stream_send rs_c(si);
  SECTION("set") {
    auto v = GENERATE(1, 2, 3, 4, 5, 6);
    so << "set_a1(" << v << ")";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);
    REQUIRE(ia_t.get_a1() == v);
  }

  SECTION("get") {
    auto v = GENERATE(1, 2, 3, 4, 5, 6);
    ia_t.set_a1(v);

    so << "get_a1()";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);
    int a;
    si >> a;
    REQUIRE(a == v);
  }

  SECTION("set/get") {
    auto v = GENERATE(1, 2, 3, 4, 5, 6);
    so << "set_a1(" << v << ")";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);

    so << "get_a1()";
    REQUIRE(ia_c.call(fs_c, rs_c) == true);
    int a;
    si >> a;
    REQUIRE(a == v);
  }
}

TEST_CASE("Interfaces Call simple function", "[Interface][Call][Function]") {

  IB_test ib_t;
  IB_caller ib_c(ib_t);
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_recv fs_c(so);
  Return_string_stream_send rs_c(si);
  SECTION("f0 - just call") {
    so << "f0()";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
  }

  SECTION("f1 - just return") {
    so << "f1()";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == 1);
  }

  SECTION("f2 - 1 params and return") {
    auto v1 = GENERATE(1, 2, 3, 4, 5);

    so << "f2(" << v1 << ")";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == (v1 + 1));
  }

  SECTION("f3 - 2 params and return") {
    auto v1 = GENERATE(1, 2, 3, 4, 5);
    auto v2 = GENERATE(1, 2, 3, 4, 5);

    so << "f3(" << v1 << "," << v2 << ")";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == (v1 + v2));
  }

  SECTION("f4 - 3 params and return") {
    auto v1 = GENERATE(-1, -2, 0, 1, 2);
    auto v2 = GENERATE(-1, -2, 0, 1, 2);
    auto v3 = GENERATE(-1, -2, 0, 1, 2);

    so << "f4(" << v1 << "," << v2 << "," << v3 << ")";
    REQUIRE(ib_c.call(fs_c, rs_c) == true);
    int a = 0;
    si >> a;
    REQUIRE(a == (v1 + v2 + v3));
  }
}

TEST_CASE("Interfaces Fake simple get/set", "[Interface][Fake][Get/Set]") {
  std::stringstream so;
  std::stringstream si;
  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  IA *b = new IA_fake(fs, rs);

  SECTION("set") {
    auto t = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9);

    b->set_a1(t);
    std::stringstream ss;
    ss << "set_a1(" << t << ")";

    REQUIRE(so.str() == ss.str());
  }

  SECTION("get") {
    auto t = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9);
    si << t;

    REQUIRE(b->get_a1() == t);
    REQUIRE(so.str() == "get_a1()");
  }

  delete (b);
}

TEST_CASE("Interfaces Fake simple function", "[Interface][Fake][Function]") {
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  IB *b = new IB_fake(fs, rs);

  SECTION("F1") {
    auto t = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9);
    si << t;
    CHECK(b->f2(t) == t);
    std::stringstream ss;
    ss << "f2(" << t << ")";
    REQUIRE(so.str() == ss.str());
    so.str("");
    si.str("");
  }
  delete (b);
}

TEST_CASE("Interfaces Fake simple", "[Interface][Fake]") {
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  IB *b = new IB_fake(fs, rs);


  SECTION("f0") {
    b->f0();
    REQUIRE(so.str() == "f0()");
  }

  SECTION("f1") {
    auto v = GENERATE(1, 2, 3);
    si << v;
    CHECK(b->f1() == v);
    REQUIRE(so.str() == "f1()");
  }

  SECTION("f2") {
    auto v = GENERATE(1, 2, 3);
    si << v;
    CHECK(b->f2(v) == v);
    std::stringstream ss;
    ss << "f2(" << v << ")";
    REQUIRE(so.str() == ss.str());
  }

  SECTION("f3") {
    auto v1 = GENERATE(1, 2, 3);
    auto v2 = GENERATE(1, 2, 3);
    si << v1 + v2;

    CHECK(b->f3(v1, v2) == v1 + v2);
    std::stringstream ss;
    ss << "f3(" << v1 << "," << v2 << ")";
    REQUIRE(so.str() == ss.str());
  }

  SECTION("f4") {
    auto v1 = GENERATE(1, 2, 3);
    auto v2 = GENERATE(1, 2, 3);
    auto v3 = GENERATE(1, 2, 3);
    si << v1 + v2 + v3;

    CHECK(b->f4(v1, v2, v3) == v1 + v2 + v3);
    std::stringstream ss;
    ss << "f4(" << v1 << "," << v2 << "," << v3<< ")";
    REQUIRE(so.str() == ss.str());
  }

  delete b;
}

TEST_CASE("Interfaces Fake simple F", "[Interface][Fake]") {
  std::stringstream so;
  std::stringstream si;
  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  IB *b = new IB_fake(fs, rs);

  si << 1 << std::endl;
  CHECK(b->f1() == 1);
  CHECK(so.str() == "f1()");

  si << 2 << std::endl;
  CHECK(b->f1() == 2);
  CHECK(so.str() == "f1()f1()");

  si << 3 << std::endl;
  CHECK(b->f1() == 3);
  CHECK(so.str() == "f1()f1()f1()");
}

