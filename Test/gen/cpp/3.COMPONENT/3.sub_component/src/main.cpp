#include <iostream>
#include "catch.hpp"

#include "Components/Empty.hpp"
#include "Components/S_C1.hpp"
#include "Components/S_C2.hpp"
#include "Components/S_C3.hpp"
#include "Components/B.hpp"
#include "Components/D.hpp"
#include "Components/F.hpp"
#include "Components/test_sc_data_c.hpp"

TEST_CASE("Component sub_component", "[Component][sub_component]") {

  std::cout << "\n->->  Empty  <-<-\n";
  {
    Empty c0;

    c0.configuration();

    c0.connection();

    c0.start();

    c0.step();
    c0.step();
    c0.step();

    c0.stop();
  }

  std::cout << "\n->->  S_C1  <-<-\n";
  {
    S_C1 c1;
    c1.configuration();

    c1.connection();

    c1.start();

    c1.step();
    c1.step();
    c1.step();

    c1.stop();
  }

  std::cout << "\n->->  S_C2  <-<-\n";
  {
    S_C2 c2;

    c2.configuration();

    c2.connection();

    c2.start();

    c2.step();
    c2.step();
    c2.step();

    c2.stop();
  }

  std::cout << "\n->->  S_C3  <-<-\n";
  {
   S_C3 c3;

    c3.configuration();

    c3.connection();

    c3.start();

    c3.step();
    c3.step();
    c3.step();

    c3.stop();
  }

  std::cout << "\n->->  S_B  <-<-\n";
  {
    B b;

    b.configuration();

    b.connection();

    b.start();

    b.step();
    b.step();
    b.step();

    b.stop();
  }

  std::cout << "\n->->  S_D  <-<-\n";
  {
    D d;

    d.configuration();

    d.connection();

    d.start();

    d.step();
    d.step();
    d.step();

    d.stop();
  }

  std::cout << "\n->->  S_F  <-<-\n";
  {
    F f;

    f.configuration();

    f.connection();

    f.start();

    f.step();
    f.step();
    f.step();

    f.stop();
  }

  std::cout << "\n->->  Sc_data_test  <-<-\n";
  {
    test_sc_data_c c;

    c.configuration();

    c.connection();

    c.start();

    c.step();

    std::cout << c.get_p1().get_a()<< std::endl;
    std::cout << c.get_p2().get_a()<< std::endl;
    c.get_p1().set_a(1);

    // both modified
    std::cout << c.get_p1().get_a()<< std::endl;
    std::cout << c.get_p2().get_a()<< std::endl;

    if(c.get_p1().get_a() != 1) {
      //      return -1;
    }

    if(c.get_p2().get_a() != 1) {
      //return -1;
    }

    c.step();

    c.stop();
  }


  //  return 0;
}
