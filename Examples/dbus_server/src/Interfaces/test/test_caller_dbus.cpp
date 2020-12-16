
#include "Interfaces/test//test_caller_dbus.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_dbus_recv.hpp"
#include "Interfaces/Return_dbus_send.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

test_caller_dbus::test_caller_dbus(test &pcomp)
    : test_p_caller_dbus(pcomp), comp(pcomp) {}

void test_caller_dbus::introspection(std::ostream &ss) {

  test_p_caller_dbus::introspection(ss);

  ss << "<method name=\"f7\">"

     << "<arg type=\"y\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f8\">"

     << "<arg type=\"q\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f9\">"

     << "<arg type=\"u\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f10\">"

     << "<arg type=\"t\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f11\">"

     << "<arg type=\"a{sv}\" name=\"a\" direction=\"in\"/>"

     << "</method>";

  ss << "<method name=\"f12\">"

     << "<arg type=\"a{sv}\" name=\"ret\" direction=\"out\"/>"

     << "</method>";

  ss << "<method name=\"get_a\">"
     << "<arg type=\"i\" name=\"ret\" direction=\"out\"/>"
     << "</method>";

  ss << "<method name=\"set_a\">"
     << "<arg type=\"i\" name=\"set\" direction=\"in\"/>"
     << "</method>";

  ss << "<property type=\"i\" name=\"a\" access=\"readwrite\"/>";

  ss << "<method name=\"get_b\">"
     << "<arg type=\"x\" name=\"ret\" direction=\"out\"/>"
     << "</method>";

  ss << "<method name=\"set_b\">"
     << "<arg type=\"x\" name=\"set\" direction=\"in\"/>"
     << "</method>";

  ss << "<property type=\"x\" name=\"b\" access=\"readwrite\"/>";
}

bool test_caller_dbus::call(CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {

  std::string name_function = msg.get_function();
  bool b = this->call(name_function, msg, reply);
  return b;
}

bool test_caller_dbus::call(std::string &name_function,
                            CompoMe::Function_dbus_recv &msg,
                            CompoMe::Return_dbus_send &reply) {
  bool result = false;

  switch (str2int(name_function.c_str())) {
    // Function

  case str2int("f7"):
    result = this->f7(msg, reply);
    break;

  case str2int("f8"):
    result = this->f8(msg, reply);
    break;

  case str2int("f9"):
    result = this->f9(msg, reply);
    break;

  case str2int("f10"):
    result = this->f10(msg, reply);
    break;

  case str2int("f11"):
    result = this->f11(msg, reply);
    break;

  case str2int("f12"):
    result = this->f12(msg, reply);
    break;

    // Get/Set

  case str2int("get_a"):
    result = this->get_a(msg, reply);
    break;
  case str2int("set_a"):
    result = this->set_a(msg, reply);
    break;

  case str2int("get_b"):
    result = this->get_b(msg, reply);
    break;
  case str2int("set_b"):
    result = this->set_b(msg, reply);
    break;

  default:
    return test_p_caller_dbus::call(name_function, msg, reply);
    break;
  };

  return result;
}

bool test_caller_dbus::f7(CompoMe::Function_dbus_recv &msg,
                          CompoMe::Return_dbus_send &reply) {

  ui8 l_a;

  msg >> l_a;

  try {

    this->comp.f7(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::f8(CompoMe::Function_dbus_recv &msg,
                          CompoMe::Return_dbus_send &reply) {

  ui16 l_a;

  msg >> l_a;

  try {

    this->comp.f8(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::f9(CompoMe::Function_dbus_recv &msg,
                          CompoMe::Return_dbus_send &reply) {

  ui32 l_a;

  msg >> l_a;

  try {

    this->comp.f9(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::f10(CompoMe::Function_dbus_recv &msg,
                           CompoMe::Return_dbus_send &reply) {

  ui64 l_a;

  msg >> l_a;

  try {

    this->comp.f10(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::f11(CompoMe::Function_dbus_recv &msg,
                           CompoMe::Return_dbus_send &reply) {

  S1 l_a;

  import_struct(msg, l_a);

  try {

    this->comp.f11(l_a);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::f12(CompoMe::Function_dbus_recv &msg,
                           CompoMe::Return_dbus_send &reply) {

  try {

    auto rep = this->comp.f12();

    export_struct(reply, rep);

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::get_a(CompoMe::Function_dbus_recv &msg,
                             CompoMe::Return_dbus_send &reply) {
  try {
    auto rep = this->comp.get_a();

    reply << rep;

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::set_a(CompoMe::Function_dbus_recv &msg,
                             CompoMe::Return_dbus_send &reply) {
  i32 set_val;

  msg >> set_val;

  try {
    this->comp.set_a(set_val);
  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::get_b(CompoMe::Function_dbus_recv &msg,
                             CompoMe::Return_dbus_send &reply) {
  try {
    auto rep = this->comp.get_b();

    reply << rep;

  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}

bool test_caller_dbus::set_b(CompoMe::Function_dbus_recv &msg,
                             CompoMe::Return_dbus_send &reply) {
  i64 set_val;

  msg >> set_val;

  try {
    this->comp.set_b(set_val);
  } catch (const CompoMe::Error &e) {
    std::stringstream ss;
    ss << "!" << &e;
    reply << ss.str();
  }

  return true;
}
