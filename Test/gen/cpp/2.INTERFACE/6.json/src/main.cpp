#include "Components/Require_helper.hpp"

#include "Interfaces/Empty/Empty.hpp"

// #include "Interfaces/Function_dbus_send.hpp"
// #include "Interfaces/IA/IA.hpp"
// #include "Interfaces/IB/IB.hpp"
#include "Interfaces/Function_json_send.hpp"
#include "Interfaces/IC/IC.hpp"
#include "Interfaces/Return_json_recv.hpp"
#include "Structs/S1.hpp"
#include "catch.hpp"

// #include <functional>

// class Function_json_send_i;

// class Return_json_recv_i : public CompoMe::Return_json_recv {
// public:
//   Function_json_send_i &_p;
//   nlohmann::json data;

//   Return_json_recv_i(Function_json_send_i &r) : _p(r), data() {
//     this->data["jsonrpc"] = "2.0";
//   }
//   virtual ~Return_json_recv_i() {}

//   void pull() override;
//   void end() override;
//   void clean();

//   nlohmann::json &get_si() override { return this->data; }
// };

// class Function_json_send_i : public CompoMe::Function_json_send {
// public:
//   Return_json_recv_i ret;
//   nlohmann::json data;

//   Function_json_send_i() : ret(*this), data() { this->data["jsonrpc"] =
//   "2.0"; } virtual ~Function_json_send_i() {} void start() override {} void
//   send() override {} void set_function(std::string str) override {
//   this->data["function"] = str; } nlohmann::json &get_so() override { return
//   this->data; }
// };

// // void Return_dbus_recv_i::pull() {
// //   this->p = dbus_message_new_method_return(this->_p.p);
// //   dbus_message_iter_init_append(this->p, &this->_a_it);

// //   this->f_t(*this, this->_a_it);
// // }

// // void Return_dbus_recv_i::end() {}
// // void Return_dbus_recv_i::clean() {
// //   if (this->p != nullptr) {
// //     dbus_message_unref(this->p);
// //     this->p = nullptr;
// //   }
// //   if (this->_p.p != nullptr) {
// //     dbus_message_unref(this->_p.p);
// //     this->_p.p = nullptr;
// //   }
// // }

// TEST_CASE("Empty Interface json", "[Interface][JSON]") {

//   CompoMe::Require_helper_t<Empty> r;

//   Function_json_send_i l_s;
//   Return_json_recv_i l_r(l_s);

//   //  auto p = r.fake_json_it(l_s, l_r);

//   // REQUIRE(p != nullptr);
//   // REQUIRE(r.connected());
// }

// TEST_CASE("IA Interface json get/set", "[Interface][JSON]") {

//   // CompoMe::Require_helper_t<IA> r;
//   // Function_json_send_i l_s;
//   // auto p = r.fake_json_it(l_s, l_s.ret);

//   // // l_s.ret.f_t = [](Return_json_recv_i &ret, DBusMessageIter &_a_it) {
//   // //   CompoMe::Serialization_context_export ctx;
//   // //   if (ret._p.member().find("get") != std::string::npos) {
//   // //     i32 i;
//   // //     _a_it << i;
//   // //   }
//   // // };

//   // REQUIRE(p != nullptr);
//   // REQUIRE(r.connected());

//   // r->set_a1(1);
//   // // REQUIRE(l_s.member() == std::string("set_a1"));
//   // // REQUIRE(l_s.signature() == std::string("i"));
//   // // REQUIRE(l_s.ret.signature() == std::string(""));
//   // // l_s.ret.clean();

//   // r->set_a2(2);
//   // // REQUIRE(l_s.member() == std::string("set_a2"));
//   // // REQUIRE(l_s.signature() == std::string("i"));
//   // // REQUIRE(l_s.ret.signature() == std::string(""));
//   // // l_s.ret.clean();

//   // r->set_a3(3);
//   // // REQUIRE(l_s.member() == std::string("set_a3"));
//   // // REQUIRE(l_s.signature() == std::string("i"));
//   // // REQUIRE(l_s.ret.signature() == std::string(""));
//   // // l_s.ret.clean();

//   // r->get_a1();
//   // // REQUIRE(l_s.member() == std::string("get_a1"));
//   // // REQUIRE(l_s.signature() == std::string(""));
//   // // REQUIRE(l_s.ret.signature() == std::string("i"));
//   // // l_s.ret.clean();

//   // r->get_a2();
//   // // REQUIRE(l_s.member() == std::string("get_a2"));
//   // // REQUIRE(l_s.signature() == std::string(""));
//   // // REQUIRE(l_s.ret.signature() == std::string("i"));
//   // // l_s.ret.clean();

//   // r->get_a3();
//   // //   REQUIRE(l_s.member() == std::string("get_a3"));
//   // //   REQUIRE(l_s.signature() == std::string(""));
//   // //   REQUIRE(l_s.ret.signature() == std::string("i"));
//   // //   l_s.ret.clean();
// }

// // TEST_CASE("IB Interface dbus functionx", "[Interface][DBUS]") {

// //   CompoMe::Require_helper_t<IB> r;
// //   Function_dbus_send_i l_s;
// //   l_s.ret.f_t = [](Return_dbus_recv_i &ret, DBusMessageIter &_a_it) {
// //     CompoMe::Serialization_context_export ctx;
// //     if (ret._p.member() != "f0") {
// //       i32 i;
// //       _a_it << i;
// //     }
// //   };

// //   auto p = r.fake_dbus_it(l_s, l_s.ret);

// //   REQUIRE(p != nullptr);
// //   REQUIRE(r.connected());

// //   r->f0();
// //   CHECK(l_s.member() == std::string("f0"));

// //   r->f1();
// //   CHECK(l_s.member() == std::string("f1"));

// //   r->f2(1);
// //   CHECK(l_s.member() == std::string("f2"));
// //   CHECK(l_s.signature() == std::string("i"));

// //   r->f3(1, 2);
// //   CHECK(l_s.member() == std::string("f3"));
// //   CHECK(l_s.signature() == std::string("ii"));

// //   r->f4(1, 2, 3);
// //   CHECK(l_s.member() == std::string("f4"));
// //   CHECK(l_s.signature() == std::string("iii"));
// // }

// // TEST_CASE("IC Interface dbus function", "[Interface][DBUS]") {

// //   CompoMe::Require_helper_t<IC> r;
// //   Function_dbus_send_i l_s;
// //   auto p = r.fake_dbus_it(l_s, l_s.ret);

// //   REQUIRE(p != nullptr);
// //   REQUIRE(r.connected());

// //   l_s.ret.f_t = [](Return_dbus_recv_i &ret, DBusMessageIter &_a_it) {
// //     CompoMe::Serialization_context_export ctx;
// //     S1 s;
// //     s.to_stream(_a_it, ctx);
// //   };

// //   {
// //     auto a = r->f0();
// //     CHECK(l_s.member() == std::string("f0"));
// //     l_s.ret.clean();
// //   }
// //   {
// //     S1 s;
// //     auto a = r->f2(s);
// //     CHECK(l_s.member() == std::string("f2"));
// //     CHECK(l_s.signature() == std::string("a{sv}"));
// //     l_s.ret.clean();
// //   }
// //   {
// //     S1 s1, s2;
// //     auto a = r->f3(s1, s2);
// //     CHECK(l_s.member() == std::string("f3"));
// //     CHECK(l_s.signature() == std::string("a{sv}a{sv}"));
// //     l_s.ret.clean();
// //   }
// // }
