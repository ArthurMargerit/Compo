#include "catch.hpp"

#include "Errors/Division_exeption.hpp"
#include "Errors/Exeption.hpp"
//#include "Errors/Exeption_fac.hpp"
#include "Errors/Math_exeption.hpp"
//#include "Errors/Math_exeption_fac.hpp"

#include "Data/code.hpp"
#include <iostream>
#include <memory>
#include <sstream>

TEST_CASE("Error Serialization simple", "[Error][Serialization]") {
  init_code();
  Exeption e;
  Exeption e_i;
  auto l_t = GENERATE(Time(1, 2), Time(0, 10), Time(-10, -5));
  e.set_t(l_t);

  std::stringstream ss;
  ss << e;
  ss >> e_i;

  CHECK(e.get_t().get_time() == e_i.get_t().get_time());
  CHECK(e.get_t().get_time_us() == e_i.get_t().get_time_us());
  CHECK(e.get_t() == e_i.get_t());
  CHECK(e == e_i);
}

TEST_CASE("Error Serialization heritage", "[Error][Serialization]") {
  init_code();
  Math_exeption e;
  Math_exeption e_i;
  auto l_t = GENERATE(Time(1, 2), Time(0, 10), Time(-10, -5));
  e.set_t(l_t);

  std::stringstream ss;
  ss << e;
  ss >> e_i;

  CHECK(e.get_t().get_time() == e_i.get_t().get_time());
  CHECK(e.get_t().get_time_us() == e_i.get_t().get_time_us());
  CHECK(e.get_t() == e_i.get_t());
  CHECK(e == e_i);
}

TEST_CASE("Error ==", "[Error][Equal]") {
  Exeption e1;
  Exeption e2;
  CHECK(e1 == e2);

  e1.set_t(Time(1,2));
  CHECK(e1 != e2);
}

TEST_CASE("Error == heritage", "[Error][Equal]") {
  Math_exeption e1;
  Math_exeption e2;
  CHECK(e1 == e2);

  e1.set_t(Time(1,2));
  CHECK(e1 != e2);
}

TEST_CASE("Error * serialization", "[Error][Serialization]") {

  Math_exeption e;
  Math_exeption * e_i = nullptr;
  std::stringstream ss;

  std::cout << &e << "\n";
  INFO("e = " << &e);
  ss << &e;
  ss >> e_i;

  CHECK(e_i != NULL);
  CHECK(e == *e_i);
}

// Math_exeption me;
// // Division_exeption de;
// // std::cout << me << std::endl;
// // std::cout << me.what() << std::endl << std::endl;

// // std::cout << de << std::endl;
// // std::cout << de.what() << std::endl;

// std::stringstream ss;
// ss << me;
// ss << &me;
// ss << &me;
// ss << &me;
// ss << &me;
// std::cout << &me;
// try {
//   //  Error *me2 = NULL;
//   std::shared_ptr<Error> pme2;
//   std::shared_ptr<Exeption> pme3;
//   std::shared_ptr<Math_exeption> pme4;

//   Error *ppme2 = NULL;
//   Math_exeption me2;

//   ss >> me2;
//   ss >> pme2;
//   ss >> pme3;
//   ss >> pme4;

//   ss >> ppme2;
//   std::cout << (pme2 != NULL) << std::endl;
//   std::cout << (pme3 != NULL) << std::endl;
//   std::cout << (pme4 != NULL) << std::endl;
//   std::cout << (ppme2 != NULL) << std::endl;

//   delete ppme2;

// } catch (char const *e) {
//   std::cout << "err" << e << std::endl;
// }
//}
