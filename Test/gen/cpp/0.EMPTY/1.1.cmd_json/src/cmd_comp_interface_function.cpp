#include "CompoMe/Json/Call.hpp"
#include "Interface1_impl.hpp"
#include "catch.hpp"
#include "json.hpp"
#include <iostream>

TEST_CASE("call interface function ", "[call][Tools][JSON]") {
  std::map<std::string, std::map<std::string, CompoMe::Caller_json *>> Mcall;

  Interface1_impl i1;
  Interface1_impl i2;
  Interface1_impl i3;

  Mcall["c1"]["i1"] = i1.get_caller_json();
  Mcall["c1"]["i2"] = i2.get_caller_json();
  Mcall["c2"]["i1"] = i3.get_caller_json();

  SECTION("simple") {
    std::string t = GENERATE("c1.aa", "c1.bb", "c2.cc");

    auto cmd_f =
        nlohmann::json::parse("{\"function\":\"" + t + ".f1\",\"params\":[]}");

    auto r = CompoMe::Json::Tools::call(Mcall, cmd_f);
    INFO(r.second);
    REQUIRE(r.first == true);
  }

  // SECTION("wrong") {
  //   auto t = GENERATE("{\"function\":\"f1\",\"params\":[]}",
  //                     "{\"function\":\"ee.f1\",\"params\":[]}",
  //                     "{\"function\":\"aa.unes\",\"params\":[]}",
  //                     "{\"function\":\"aa.aa.unes\",\"params\":[]}");
  //   INFO(t);
  //   auto cmd_f = nlohmann::json::parse(t);
  //   REQUIRE_THROWS(CompoMe::Json::Tools::call(Mcall, cmd_f));
  // }
}
