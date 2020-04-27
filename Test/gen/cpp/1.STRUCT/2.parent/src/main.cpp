#include "catch.hpp"

#include "Data/Struct.hpp"
#include "Data/Struct_fac.hpp"

// #include "Data/Struct_A.hpp"
// #include "Data/Struct_AA.hpp"
// #include "Data/Struct_AAA.hpp"
// #include "Data/Struct_AAAA.hpp"
// #include "Data/Struct_AAAAA.hpp"
#include "Data/Struct_AAAAAA.hpp"

#include "Data/code.hpp"
#include <sstream>

TEST_CASE("Type Parent", "[Type][Parent]") {
  init_code();
  {
    AAAAAA a;
    a.set_a1(1);
    a.set_a2(2);
    a.set_a3(3);
    a.set_a4(4);
    a.set_a5(5);
    a.set_a6(6);

    AAAAAA *p1 = NULL;
    AAAAA *p2 = NULL;
    AAAA *p3 = NULL;
    AAA *p4 = NULL;
    AA *p5 = NULL;
    A *p6 = NULL;
    Struct *p7 = NULL;

    std::stringstream ss;
    std::cout << &a;
    ss << &a << &a << &a << &a << &a << &a << &a;
    ss >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;
  }
  {
    AAAAA a;
    a.set_a1(1);
    a.set_a2(2);
    a.set_a3(3);
    a.set_a4(4);
    a.set_a5(5);

    AAAAA *p2 = NULL;
    AAAA *p3 = NULL;
    AAA *p4 = NULL;
    AA *p5 = NULL;
    A *p6 = NULL;
    Struct *p7 = NULL;

    std::stringstream ss;
    std::cout << &a;
    ss << &a << &a << &a << &a << &a << &a;
    ss >> p2 >> p3 >> p4 >> p5 >> p6 >> p7;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;
  }
  {
    AAAA a;
    a.set_a1(1);
    a.set_a2(2);
    a.set_a3(3);
    a.set_a4(4);

    AAAA *p3 = NULL;
    AAA *p4 = NULL;
    AA *p5 = NULL;
    A *p6 = NULL;
    Struct *p7 = NULL;

    std::stringstream ss;
    std::cout << &a;
    ss << &a << &a << &a << &a << &a;
    ss >> p3 >> p4 >> p5 >> p6 >> p7;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;
  }
  {
    AAA a;
    a.set_a1(1);
    a.set_a2(2);
    a.set_a3(3);

    AAA *p4 = NULL;
    AA *p5 = NULL;
    A *p6 = NULL;
    Struct *p7 = NULL;

    std::stringstream ss;
    std::cout << &a;
    ss << &a << &a << &a << &a;
    ss >> p4 >> p5 >> p6 >> p7;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;
  }
  {
    AA a;
    a.set_a1(1);
    a.set_a2(2);

    AA *p5 = NULL;
    A *p6 = NULL;
    Struct *p7 = NULL;

    std::stringstream ss;
    std::cout << &a;
    ss << &a << &a << &a;
    ss >> p5 >> p6 >> p7;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;
  }

  {
    std::shared_ptr<Struct> s = std::make_shared<AAAAAA>();
    std::shared_ptr<A> sa = std::make_shared<AAAAAA>();
    std::shared_ptr<AA> saa = std::make_shared<AAAAAA>();
    std::shared_ptr<AAA> saaa = std::make_shared<AAAAAA>();
    std::shared_ptr<AAAA> saaaa = std::make_shared<AAAAAA>();
    std::shared_ptr<AAAAA> saaaaa = std::make_shared<AAAAAA>();
    std::shared_ptr<AAAAAA> saaaaaa = std::make_shared<AAAAAA>();
  }
}
