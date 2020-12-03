#include "catch.hpp"
#include "Bus_Events/Bus_B.hpp"
#include "Bus/Bus.hpp"
#include "Components/C1.hpp"
#include "Components/C2.hpp"
#include "Components/C3.hpp"
#include <iostream>
#include <regex>

class Bus_B_impl: public Bus_B {
public:
  Bus_B_impl(){}
  virtual ~Bus_B_impl(){}

  void m(ev1 &p_e) override {
    std::cout << p_e << "\n";
  }

  void m(ev2 &p_e) override {
    std::cout << p_e << "\n";
  }

  void m(ev3 &p_e) override{
    std::cout << p_e << "\n";
  }

  void m(ev4 &p_e) override{
    std::cout << p_e << "\n";
  }
};

class Bus_C_impl: public Bus_C {
public:
  Bus_C_impl(){}
  virtual ~Bus_C_impl(){}

  void m(ev2 &p_e) override {
    std::cout << p_e << "\n";
  }
};

class Bus_D_impl: public Bus_D {
public:
  Bus_D_impl(){}
  virtual ~Bus_D_impl(){}

  void m(ev3 &p_e) override {
    std::cout << p_e << "\n";
  }

  void m(ev4 &p_e) override {
    std::cout << p_e << "\n";
  }
};

class Bus_E_impl: public Bus_E {
public:
  Bus_E_impl(){}
  virtual ~Bus_E_impl(){}

  void m(ev4 &p_e) override {
    std::cout << p_e << "\n";
  }
};

int main(int argc, char *argv[])
{
{
  CompoMe::Emit emit_1("a");
  CompoMe::Emit emit_2("b");

  Bus_B_impl b1;
  Bus_C_impl b2;
  Bus_D_impl b3;
  Bus_E_impl b4;

  emit_1.inscribe(&b1);
  emit_1.inscribe(&b2);
  emit_1.inscribe(&b3);
  emit_1.inscribe(&b4);

  emit_2.inscribe(&b1);
  emit_2.inscribe(&b2);
  emit_2.inscribe(&b3);
  emit_2.inscribe(&b4);

  // comment ////////////////////////////////////////////////////////////////////
  ev1 e1;
  ev2 e2;
  ev3 e3;
  ev4 e4;
  emit_1.push(&e1);
  emit_1.push(&e2);
  emit_1.push(&e3);
  emit_1.push(&e4);
  emit_2.push(&e1);
  emit_2.push(&e2);
  emit_2.push(&e3);
  emit_2.push(&e4);

  std::cout << "-----" << "\n";
  b1.process();
  std::cout << "-----" << "\n";
  b2.process();
  std::cout << "-----" << "\n";
  b3.process();
  std::cout << "-----" << "\n";
  b4.process();
  std::cout << "-----" << "\n";
}
 {
   CompoMe::Emit emit("a");
   Bus_B_impl b1;
   Bus_B_impl b2;
   Bus_B_impl b3;
   Bus_B_impl b4;
   emit.inscribe(&b1, "a");
   emit.inscribe(&b2, "b");
   emit.inscribe(&b3, "a|b");
   emit.inscribe(&b4, ".*");

   ev1 e1;
   e1.set_origin("a");
   emit.push(&e1);

   e1.set_origin("b");
   emit.push(&e1);

   e1.set_origin("o");
   emit.push(&e1);

   std::cout << "*****" << "\n";
   b1.process();
   std::cout << "*****" << "\n";
   b2.process();
   std::cout << "*****" << "\n";
   b3.process();
   std::cout << "*****" << "\n";
   b4.process();
   std::cout << "*****" << "\n";
 }

 {
   CompoMe::Emit emit("a");
   Bus_B_impl b1;
   Bus_B_impl b2;
   Bus_B_impl b3;
   Bus_B_impl b4;

   emit.inscribe(&b1, ".*","me");
   emit.inscribe(&b2, ".*","lapin");
   emit.inscribe(&b3, ".*","me|lapin");
   emit.inscribe(&b4, ".*",".*");

   ev1 e1;
   e1.set_destination("me");
   emit.push(&e1);

   e1.set_destination("lapin");
   emit.push(&e1);

   e1.set_destination("other");
   emit.push(&e1);

   std::cout << "+++++" << "\n";
   b1.process();
   std::cout << "+++++" << "\n";
   b2.process();
   std::cout << "+++++" << "\n";
   b3.process();
   std::cout << "+++++" << "\n";
   b4.process();
   std::cout << "+++++" << "\n";
 }

 {
   CompoMe::Emit emit("a");
   Bus_B_impl b1;
   Bus_B_impl b2;
   Bus_B_impl b3;
   Bus_B_impl b4;

   emit.inscribe(&b1, "a","b");
   emit.inscribe(&b2, "a","a");
   emit.inscribe(&b3, "a","b");
   emit.inscribe(&b4, "b","a");

   ev1 e1;
   e1.set_origin("a");
   e1.set_destination("a");
   emit.push(&e1);

   e1.set_origin("b");
   e1.set_destination("b");
   emit.push(&e1);

   e1.set_origin("a");
   e1.set_destination("b");
   emit.push(&e1);

   e1.set_origin("b");
   e1.set_destination("a");
   emit.push(&e1);

   std::cout << "/////" << "\n";
   b1.process();
   std::cout << "/////" << "\n";
   b2.process();
   std::cout << "/////" << "\n";
   b3.process();
   std::cout << "/////" << "\n";
   b4.process();
   std::cout << "/////" << "\n";
 }

 {
   ev1 e1;
   ev2 e2;
   ev3 e3;

   CompoMe::Emit emit("a");
   C3 b;
   b.configuration();
   Bus_B_impl b1;
   b.e1.inscribe(&b1);

   b.connection();
   b.start();
   b.get_b1().push(&e1);
   b.get_b1().push(&e2);
   b.get_b1().push(&e3);

   b.step();
   
   b1.process();
   b.stop();
 }

 return 0;
}
