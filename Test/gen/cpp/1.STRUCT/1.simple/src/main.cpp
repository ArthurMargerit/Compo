#include "catch.hpp"

#include "Structs/A.hpp"
#include "Structs/A1.hpp"
#include "Structs/B.hpp"
#include "Structs/C.hpp"
#include "Structs/Dot.hpp"
#include "Structs/Empty.hpp"
#include "Structs/Pos.hpp"
#include "Structs/Square.hpp"

#include "Data/code.hpp"

#include <memory>
#include <sstream>

template <typename T> bool test_stream_simple(T t1) {
  T t2;

  std::stringstream ss;
  ss << t1;
  ss >> t2;

  INFO("t1= " << t1);
  INFO("t2= " << t2);

  REQUIRE(t1 == t2);

  return true;
}

template <typename T> bool test_stream_pointer(T t1) {
  T *t2 = nullptr;

  std::stringstream ss;
  ss << &t1;
  ss >> t2;

  INFO("t1= " << &t1);
  INFO("t2= " << &t2);

  REQUIRE(t2 != NULL);
  REQUIRE(t1 == *t2);

  if (t2 != NULL) {
    delete t2;
  }

  return true;
}

template <typename T> bool test_stream_smartpointer(T t1) {
  std::shared_ptr<T> t2 = nullptr;

  std::stringstream ss;
  ss << &t1;
  ss >> t2;

  INFO("t1= " << t1);
  INFO("t2= " << t2);

  REQUIRE(t2 != nullptr);
  REQUIRE(t1 == *t2);

  return true;
}

template <typename T> bool test_stream(T t1) {
  SECTION("Direct") { test_stream_simple(t1); }
  SECTION("Pointer") {
    std::cout << t1 << "\n";
    std::cout << &t1 << "\n";
    test_stream_pointer(t1); }
  SECTION("SmartPointer") { test_stream_smartpointer(t1); }
  return false;
}


// Test Stream ////////////////////////////////////////////////////////////////
TEST_CASE("Struct serialization of one field Struct",
          "[Struct][Serialization][Simple][int]") {
  init_code();

  A a;
  test_stream(a);
  SECTION("test 0-100") {
    auto v = GENERATE(range(-100, 100));
    a.a_a() = v;
    INFO("a = " << a );
    test_stream(a);
  }
}

TEST_CASE("Struct serialization of two field Struct",
          "[Struct][Serialization][Simple][int]") {
  init_code();

  A1 a1;
  a1.a_a() = GENERATE(range(-10, 10));
  a1.a_b() = GENERATE(range(-10, 10));
  test_stream(a1);
}

TEST_CASE("Struct serialization empty with function Struct",
          "[Struct][Serialization][Empty][Function]") {
  init_code();

  B b;
  test_stream(b);

  b.a0();

  int br1 = b.a1();
  int br2 = b.a2(1);
  int br3 = b.a3(1, 2);
  int br4 = b.a4(1, 2, 3);
}

TEST_CASE("Struct serialization of Empty Struct",
          "[Struct][Serialization][empty]") {
  init_code();
  SECTION("Basic String") {
    Empty e;
    test_stream(e);
  }

  SECTION("String Stream") {
    Empty e;
    std::stringstream ss;
    ss << e;

    std::string s = ss.str();

    auto t = s.find("{");
    REQUIRE(t == 0);
    s.find("type:");
    REQUIRE(t != std::string::npos);
    s.find("addr:");
    REQUIRE(t != std::string::npos);
    s.find("}");
    REQUIRE(t != (s.length() - 1));
  }
}

TEST_CASE("Struct serialization with sub struct",
          "[Struct][Serialization][substruct]") {
  init_code();

  Pos p;
  p.set_x(GENERATE(range(0, 10)));
  p.set_y(GENERATE(range(0, 10)));

  Dot d;
  d.set_h(GENERATE(range(1, 3)));
  d.set_w(GENERATE(range(1, 3)));

  Square s;
  s.set_position(p);
  s.set_size(d);

  test_stream(s);
}

TEST_CASE("Chain serialization with simple Struct",
          "[Struct][Serialization][Struct]") {
  init_code();

  A *s1, *s2, *s3;
  A sa, sb, sc;
  sa.a_a() = GENERATE(range(-10, 10));
  sb.a_a() = GENERATE(range(-10, 10));
  sc.a_a() = GENERATE(range(-10, 10));

  std::stringstream s;
  s << &sa << &sb << &sc;
  s >> s1 >> s2 >> s3;

  INFO("sa " << sa);
  INFO("s1 " << s1);

  INFO("sb " << sb);
  INFO("s2 " << s2);

  INFO("sc " << sc);
  INFO("s3 " << s3);

  REQUIRE(sa == *s1);
  REQUIRE(sb == *s2);
  REQUIRE(sc == *s3);
}

TEST_CASE("Struct serialization with smartpointer",
          "[Struct][Serialization][substruct]") {
  init_code();

  A sa;
  std::shared_ptr<A> psa = std::make_shared<A>();
  std::shared_ptr<A> psb = std::make_shared<A>();
  auto r = GENERATE(range(0, 1000));
  psa->set_a(r);

  std::stringstream ss;
  ss << *psa;
  ss >> *psb;

  INFO("psa " << psa);
  INFO("psb " << psb);

  REQUIRE(psa->get_a() == r);
  REQUIRE(psb->get_a() == r);
}

// {
//   std::shared_ptr<Struct> psa = std::make_shared<A>();
//   std::shared_ptr<A> psb = std::make_shared<A>();

//   std::cout << psa << std::endl;
//   std::cout << psb << std::endl;
// }
// }
