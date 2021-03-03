#include "Events/e_sr.hpp"
#include "Events/e_sr_2.hpp"
#include "Events/ev1.hpp"
#include "Events/ev2.hpp"
#include "Events/ev3.hpp"
#include "Serialization_context.hpp"
#include "catch.hpp"
#include "json.hpp"

TEST_CASE("Test empty", "[Event][JSON]") {
  ev1 ea, ea_i;
  nlohmann::json j;
  CompoMe::Serialization_context_export ctx_exp;
  CompoMe::Serialization_context_import ctx_imp;
  ea.to_json(j, ctx_exp);
  ea_i.from_json(j, ctx_imp);
  CHECK(ea_i == ea);
}

TEST_CASE("Test struct", "[Event][JSON]") {
  ev2 ea, ea_i;
  ea.a_sa().a_i() = GENERATE(1, 2, 3);
  ea.a_sb().a_i() = GENERATE(1, 2, 3);

  nlohmann::json j;
  CompoMe::Serialization_context_export ctx_exp;
  CompoMe::Serialization_context_import ctx_imp;
  ea.to_json(j, ctx_exp);
  ea_i.from_json(j, ctx_imp);
  CHECK(ea_i.a_sa().a_i() == ea.a_sa().a_i());
  CHECK(ea_i.a_sb().a_i() == ea.a_sb().a_i());
  CHECK(ea_i == ea);
}

TEST_CASE("Test type", "[Event][JSON]") {
  ev3 ea, ea_i;
  ea.a_sc() = GENERATE(1, 2, 3);

  nlohmann::json j;
  CompoMe::Serialization_context_export ctx_exp;
  CompoMe::Serialization_context_import ctx_imp;
  ea.to_json(j, ctx_exp);
  ea_i.from_json(j, ctx_imp);
  CHECK(ea_i.a_sc() == ea.a_sc());
  CHECK(ea_i == ea);
}

TEST_CASE("Test parrent", "[Event][JSON]") {

  nlohmann::json j;
  CompoMe::Serialization_context_export ctx_exp;
  CompoMe::Serialization_context_import ctx_imp;

  SECTION("parent") {
    e_sr ea, ea_i;
    ea.to_json(j, ctx_exp);
    ea_i.from_json(j, ctx_imp);

    CHECK(j["type"] == "e_sr");
    CHECK(j["addr"] != nullptr);

    CHECK(ea.get_ia1() == ea_i.get_ia1());
    CHECK(ea.get_ia2() == ea_i.get_ia2());
    CHECK(ea == ea_i);
  }

  SECTION("child") {
    e_sr_2 eb, eb_i;
    eb.to_json(j, ctx_exp);
    eb_i.from_json(j, ctx_imp);

    CHECK(j["type"] == "e_sr_2");
    CHECK(j["addr"] != nullptr);

    CHECK(j["parent"] != nullptr);
    CHECK(j["parent"]["type"] == "e_sr");
    CHECK(j["parent"]["addr"] != nullptr);

    // field of parent
    CHECK(eb.get_ia1() == eb_i.get_ia1());
    CHECK(eb.get_ia2() == eb_i.get_ia2());

    // field of child
    CHECK(eb.get_ib1() == eb_i.get_ib1());
    CHECK(eb.get_ib2() == eb_i.get_ib2());
    CHECK(eb == eb_i);
  }
}
