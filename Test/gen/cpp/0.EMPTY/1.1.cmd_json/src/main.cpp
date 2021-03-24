#include "CompoMe/Json/Call.hpp"
#include "Interface1_impl.hpp"
#include "catch.hpp"
#include "json.hpp"
#include <iostream>

TEST_CASE("call", "[call][Tools][call][JSON]") {

  Interface1_impl i;
  auto i_caller = i.get_caller_json();
  SECTION("f1 json") {
    auto cmd = GENERATE(
        nlohmann::json::parse("{ \"function\": \"f1\", \"params\": null}"),
        nlohmann::json::parse("{ \"function\": \"f1\", \"params\": {}}"),
        nlohmann::json::parse("{ \"function\": \"f1\", \"params\": []}"));
    INFO("cmd" << cmd.dump());
    auto r1 = CompoMe::Json::Tools::call(i_caller, cmd);
    INFO("result:" << r1.second);
    REQUIRE(r1.first == true);
    CHECK(r1.second["result"] == nullptr);
  }

  SECTION("f2 json") {
    auto cmd = GENERATE(
        nlohmann::json::parse(
            "{ \"function\": \"f2\", \"params\": {\"a\":1,\"b\":2}}"),
        nlohmann::json::parse("{ \"function\": \"f2\", \"params\": [1,2]}"));
    INFO("cmd" << cmd.dump());
    auto r1 = CompoMe::Json::Tools::call(i_caller, cmd);
    INFO("result:" << r1.second);
    REQUIRE(r1.first == true);
    CHECK(r1.second["result"] == nullptr);
  }

  SECTION("f3 json") {
    auto cmd = GENERATE(
        nlohmann::json::parse(
            "{ \"function\": \"f3\", \"params\": {\"a\":1,\"b\":2,\"c\":3}}"),
        nlohmann::json::parse("{ \"function\": \"f3\", \"params\": [1,2,3]}"));
    INFO("cmd" << cmd.dump());
    auto r1 = CompoMe::Json::Tools::call(i_caller, cmd);
    INFO("result:" << r1.second);
    REQUIRE(r1.first == true);
    CHECK(r1.second["result"] == 6);
  }

  SECTION("f4 json") {
    auto cmd =
        GENERATE(nlohmann::json::parse("{\"function\":\"f4\",\"params\":{"
                                       "\"a\":{\"type\":\"A\",\"v1\":1}"
                                       ","
                                       "\"b\":{\"type\":\"A\",\"v1\":3}}"
                                       "}"),
                 nlohmann::json::parse("{\"function\": \"f4\","
                                       "\"params\": "
                                       "[{\"type\":\"A\",\"v1\":1},"
                                       "{\"type\":\"A\",\"v1\":3}]}"));

    INFO("cmd" << cmd.dump());
    auto r1 = CompoMe::Json::Tools::call(i_caller, cmd);
    INFO("result:" << r1.second);
    REQUIRE(r1.first == true);
    CHECK(r1.second["result"]["addr"] != nullptr);
    CHECK(r1.second["result"]["type"] == "A");
    CHECK(r1.second["result"]["v1"] == 4);
  }
}

TEST_CASE("call get/set", "[call][Tools][Terms]") {

  Interface1_impl i;
  auto i_caller = i.get_caller_json();

  for (int i = 0; i < 10000; ++i) {
    auto cmd_set = nlohmann::json::parse(
        "{\"function\":\"set_data1\",\"params\":[" + std::to_string(i) + "]}");
    auto r6 = CompoMe::Json::Tools::call(i_caller, cmd_set);
    CHECK(r6.first == true);
    CHECK(r6.second == nullptr);

    auto cmd_get =
        nlohmann::json::parse("{\"function\":\"get_data1\",\"params\":[]}");
    auto r7 = CompoMe::Json::Tools::call(i_caller, cmd_get);
    CHECK(r7.first == true);
    CHECK(r7.second["result"] == i);
  }
}

TEST_CASE("call function", "[call][Tools][Terms]") {
  Interface1_impl i;
  auto i_caller = i.get_caller_json();
  for (int i = 0; i < 30; ++i) {
    for (int j = 0; j < 30; ++j) {
      for (int k = 0; k < 30; ++k) {
        auto cmd_f =
            nlohmann::json::parse("{\"function\":\"f3\",\"params\":[0,0,0]}");
        cmd_f["params"][0] = i;
        cmd_f["params"][1] = j;
        cmd_f["params"][2] = k;
        auto r7 = CompoMe::Json::Tools::call(i_caller, cmd_f);
        CHECK(r7.first == true);
        CHECK(r7.second["result"] == (i + j + k));
      }
    }
  }
}
