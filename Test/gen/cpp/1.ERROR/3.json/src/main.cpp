#include "Data/code.hpp"
#include "Errors/E1.hpp"
#include "Errors/E2.hpp"
#include "Errors/E3.hpp"
#include "Errors/E4.hpp"
#include "catch.hpp"
#include "json.hpp"
#include <memory>

template <typename T> void my_test(const T &in, T &out) {
  nlohmann::json j;

  CompoMe::Serialization_context_import s_i;
  CompoMe::Serialization_context_export s_x;

  in.to_json(j, s_x);
  out.from_json(j, s_i);
}

TEST_CASE("Error Serialization simple", "[Error][Serialization][JSON]") {
  init_code();
  E1 e, e_i;
  auto l_t = GENERATE(Time(1, 2), Time(0, 10), Time(-10, -5));
  auto l_i = GENERATE(1, 2, 3);
  e.set_t1(l_t);
  e.set_i1(l_i);

  SECTION("in > json > out //test") {
    my_test(e, e_i);
    CHECK(e.get_t1().get_time() == e_i.get_t1().get_time());
    CHECK(e.get_t1().get_time_us() == e_i.get_t1().get_time_us());
    CHECK(e.get_t1() == e_i.get_t1());
    CHECK(e.get_i1() == e_i.get_i1());
    CHECK(e == e_i);
  }

  SECTION("Check json form") {
    nlohmann::json j;
    CompoMe::Serialization_context_export s_x;

    e.to_json(j, s_x);
    REQUIRE(j["type"] == "E1");
    REQUIRE(j["addr"] != 0);
    REQUIRE(j["t1"]["time"] == l_t.get_time());
    REQUIRE(j["t1"]["time_us"] == l_t.get_time_us());
    REQUIRE(j["i1"] == l_i);
  }
}

TEST_CASE("Error Serialization with parrent", "[Error][Serialization][JSON]") {
  init_code();
  E2 e, e_i;
  auto l_t1 = GENERATE(Time(1, 2), Time(0, 10), Time(-10, -5));
  auto l_t2 = GENERATE(Time(1, 2), Time(0, 10), Time(-10, -5));
  auto l_i1 = GENERATE(1, 2, 3);
  auto l_i2 = GENERATE(1, 2, 3);

  e.set_t1(l_t1);
  e.set_i1(l_i1);
  e.set_t2(l_t2);
  e.set_i2(l_i2);

  SECTION("in > json > out //test") {
    my_test(e, e_i);

    // t1
    CHECK(e.get_t1().get_time() == e_i.get_t1().get_time());
    CHECK(e.get_t1().get_time_us() == e_i.get_t1().get_time_us());
    CHECK(e.get_t1() == e_i.get_t1());

    // i1
    CHECK(e.get_i1() == e_i.get_i1());

    // t2
    CHECK(e.get_t2().get_time() == e_i.get_t2().get_time());
    CHECK(e.get_t2().get_time_us() == e_i.get_t2().get_time_us());
    CHECK(e.get_t2() == e_i.get_t2());

    // i2
    CHECK(e.get_i2() == e_i.get_i2());

    // ==
    CHECK(e == e_i);
  }

  SECTION("Check json form") {
    nlohmann::json j;
    CompoMe::Serialization_context_export s_x;

    e.to_json(j, s_x);
    REQUIRE(j["type"] == "E2");
    REQUIRE(j["addr"] != 0);
    REQUIRE(j["t2"]["time"] == l_t2.get_time());
    REQUIRE(j["t2"]["time_us"] == l_t2.get_time_us());
    REQUIRE(j["i2"] == l_i2);

    auto j_p = j["parent"];
    REQUIRE(j_p["type"] == "E1");
    REQUIRE(j_p["addr"] != 0);
    REQUIRE(j_p["t1"]["time"] == l_t1.get_time());
    REQUIRE(j_p["t1"]["time_us"] == l_t1.get_time_us());
    REQUIRE(j_p["i1"] == l_i1);
  }
}

// TEST_CASE("Error * serialization", "[Error][Serialization]") {
//   init_code();
//   E1 e;
//   E1 *e_i = nullptr;
//   INFO("e = " << &e);
//   nlohmann::json j;

//   ss << &e;
//   ss >> e_i;

//   CHECK(e_i != NULL);
//   CHECK(e == *e_i);
// }

// // Math_exeption me;
// // // Division_exeption de;
// // // std::cout << me << std::endl;
// // // std::cout << me.what() << std::endl << std::endl;

// // // std::cout << de << std::endl;
// // // std::cout << de.what() << std::endl;

// // std::stringstream ss;
// // ss << me;
// // ss << &me;
// // ss << &me;
// // ss << &me;
// // ss << &me;
// // std::cout << &me;
// // try {
// //   //  Error *me2 = NULL;
// //   std::shared_ptr<Error> pme2;
// //   std::shared_ptr<Exeption> pme3;
// //   std::shared_ptr<Math_exeption> pme4;

// //   Error *ppme2 = NULL;
// //   Math_exeption me2;
// //   ss >> me2;
// //   ss >> pme2;
// //   ss >> pme3;
// //   ss >> pme4;
// //   ss >> ppme2;
// //   std::cout << (pme2 != NULL) << std::endl;
// //   std::cout << (pme3 != NULL) << std::endl;
// //   std::cout << (pme4 != NULL) << std::endl;
// //   std::cout << (ppme2 != NULL) << std::endl;
// //   delete ppme2;
// // } catch (char const *e) {
// //   std::cout << "err" << e << std::endl;
// // }
// //}
