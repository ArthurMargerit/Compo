// #include "Data/code.hpp"
// #include "catch.hpp"
// #include <dbus/dbus.h>

// TEST_CASE("Type dbus", "[Type][Simple][Dbus]") {
//   Empty e = GENERATE(1, 2, 3, 4);
//   Empty e_i = 0;
//   DBusMessageIter iter_r;
//   DBusMessageIter iter_w;
//   DBusMessage *msg =
//       dbus_message_new_method_call("test.method.server", "/test/method/Object",
//                                    "test.method.Type", "Method");

//   dbus_message_iter_init_append(msg, &iter_w);
//   iter_w << e;

//   dbus_message_iter_init(msg, &iter_r);
//   iter_r >> e_i;

//   CHECK(e == e_i);
//   dbus_message_unref(msg);
//   dbus_shutdown();
// }

// TEST_CASE("Type dbus many", "[Type][Simple][Dbus]") {
//   Empty e1 = GENERATE(1, 2, 3, 4);
//   Empty e2 = GENERATE(1, 2, 3, 4);
//   Empty e3 = GENERATE(1, 2, 3, 4);

//   Empty e1_i = 0;
//   Empty e2_i = 0;
//   Empty e3_i = 0;

//   DBusMessageIter iter_r;
//   DBusMessageIter iter_w;
//   DBusMessage *msg =
//       dbus_message_new_method_call("test.method.server", "/test/method/Object",
//                                    "test.method.Type", "Method");

//   dbus_message_iter_init_append(msg, &iter_w);
//   iter_w << e1 << e2 << e3;

//   dbus_message_iter_init(msg, &iter_r);
//   iter_r >> e1_i >> e2_i >> e3_i;

//   CHECK(e1 == e1_i);
//   CHECK(e2 == e2_i);
//   CHECK(e3 == e3_i);
//   std::string r = dbus_message_get_signature(msg);
//   CHECK(r == "iii");

//   dbus_message_unref(msg);
//   dbus_shutdown();
// }

// TEST_CASE("Type test _max_ dbus", "[Type][Simple][Dbus]") {
//   Empty e = 1;
//   Empty e_i = 0;
//   DBusMessageIter iter_r;
//   DBusMessageIter iter_w;
//   DBusMessage *msg =
//       dbus_message_new_method_call("test.method.server", "/test/method/Object",
//                                    "test.method.Type", "Method");

//   dbus_message_iter_init_append(msg, &iter_w);
//   for (int i = 0; i < 255; ++i) {
//     iter_w << (Empty)i;
//   }

//   dbus_message_iter_init(msg, &iter_r);
//   for (int i = 0; i < 255; ++i) {
//     iter_r >> e_i;
//     CHECK(e_i == i);
//   }

//   dbus_message_unref(msg);
//   dbus_shutdown();
// }

// TEST_CASE("Type test enum dbus", "[Type][Simple][Dbus]") {
//   E1 e = GENERATE(E1::A, E1::B, E1::C);
//   E1 e_i = E1::A;

//   DBusMessageIter iter_r;
//   DBusMessageIter iter_w;
//   DBusMessage *msg =
//       dbus_message_new_method_call("test.method.server", "/test/method/Object",
//                                    "test.method.Type", "Method");

//   dbus_message_iter_init_append(msg, &iter_w);
//   iter_w << e;

//   dbus_message_iter_init(msg, &iter_r);
//   iter_r >> e_i;

//   CHECK(e == e_i);

//   dbus_message_unref(msg);
//   dbus_shutdown();
// }

// TEST_CASE("Type test complexe dbus", "[Type][Simple][Dbus]") {
//   S2 e;
//   S2 e_i;

//   e[0] = E1::A;
//   e[1] = E1::B;
//   e[2] = E1::C;
//   e[3] = E1::A;
//   e[4] = E1::B;
//   e[5] = E1::C;
//   e[6] = E1::A;
//   e[7] = E1::B;
//   e[8] = E1::C;
//   e[9] = E1::A;

//   DBusMessageIter iter_r;
//   DBusMessageIter iter_w;

//   DBusMessage *msg =
//       dbus_message_new_method_call("test.method.server", "/test/method/Object",
//                                    "test.method.Type", "Method");

//   dbus_message_iter_init_append(msg, &iter_w);
//   iter_w << e;

//   dbus_message_iter_init(msg, &iter_r);
//   iter_r >> e_i;

//   for (std::size_t i = 0; i < e.size(); ++i) {
//     CHECK(e[i] == e_i[i]);
//   }


//   dbus_message_unref(msg);
//   dbus_shutdown();
// }
