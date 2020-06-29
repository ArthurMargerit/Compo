#include "catch.hpp"
#include <sstream>

#include "Test.hpp"
#include "Interfaces/IA/IA_fake_stream.hpp"
#include "Interfaces/IB/IB_fake_stream.hpp"

#include "Components/Require_helper.hpp"

TEST_CASE("Interfaces // require_helper", "[Interface][Fake][Function]") {
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  Require_helper_t<IB> r;
  auto l_v = r.fake_stream_it(fs,rs);

  CHECK(l_v != nullptr );
  CHECK(r.connected());
}

TEST_CASE("Interfaces Fake simple function", "[Interface][Fake][Function]") {
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  IB *b = new IB_fake_stream(fs, rs);

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
  IB *b = new IB_fake_stream(fs, rs);


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
  IB *b = new IB_fake_stream(fs, rs);

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

TEST_CASE("Interfaces Fake simple get/set", "[Interface][Fake][Get/Set]") {
  std::stringstream so;
  std::stringstream si;
  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  IA *b = new IA_fake_stream(fs, rs);

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
