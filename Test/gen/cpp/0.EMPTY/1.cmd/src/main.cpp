#include "CompoMe/Tools/Call.hpp"
#include "Interface1_impl.hpp"
#include "catch.hpp"

TEST_CASE("call", "[call][Tools][Terms]") {

  Interface1_impl i;
  auto i_caller = i.get_caller_stream();
  auto r1 = CompoMe::Tools::call(i_caller, "f1()");
  CHECK(r1.first == true);
  CHECK(r1.second == "");

  auto r2 = CompoMe::Tools::call(i_caller, "f2(1,2)");
  CHECK(r2.first == true);
  CHECK(r2.second == "");

  auto r3 = CompoMe::Tools::call(i_caller, "f3(1,2,3)");
  CHECK(r3.first == true);
  CHECK(r3.second == "6");

  auto r4 = CompoMe::Tools::call(i_caller, "set_data1(1)");
  CHECK(r4.first == true);
  CHECK(r4.second == "");

  auto r5 = CompoMe::Tools::call(i_caller, "set_data2(2)");
  CHECK(r5.first == true);
  CHECK(r5.second == "");

  auto r6 = CompoMe::Tools::call(i_caller, "get_data1()");
  CHECK(r6.first == true);
  CHECK(r6.second == "1");

  auto r7 = CompoMe::Tools::call(i_caller, "get_data2()");
  CHECK(r7.first == true);
  CHECK(r7.second == "2");
}

TEST_CASE("call get/set", "[call][Tools][Terms]") {

  Interface1_impl i;
  auto i_caller = i.get_caller_stream();

  for (int i = 0; i < 10000; ++i) {
    auto r6 =
        CompoMe::Tools::call(i_caller, "set_data1(" + std::to_string(i) + ")");
    CHECK(r6.first == true);
    CHECK(r6.second == "");

    auto r7 = CompoMe::Tools::call(i_caller, "get_data1()");
    CHECK(r7.first == true);
    CHECK(r7.second == std::to_string(i));
  }
}

TEST_CASE("call function", "[call][Tools][Terms]") {
  Interface1_impl i;
  auto i_caller = i.get_caller_stream();
  for (int i = 0; i < 30; ++i) {
    for (int j = 0; j < 30; ++j) {
      for (int k = 0; k < 30; ++k) {
        auto r7 = CompoMe::Tools::call(i_caller, "f3("+std::to_string(i)+","+std::to_string(j)+","+std::to_string(k)+")");
        CHECK(r7.first == true);
        CHECK(r7.second == std::to_string(i+j+k));
      }
    }
  }
}
