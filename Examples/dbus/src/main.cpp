
#include "Interfaces/Calculator/Calculator.hpp"
#include "Interfaces/test/test.hpp"
#include <unistd.h>

#include "Links/Dbus_server/Dbus_server.hpp"

class CalInterface : public Calculator {
public:
  CalInterface() {}
  virtual ~CalInterface() {}
  double add(double a, double b) override {
    std::cout << "-> add(" << a << "," << b << ")\n";
    return a + b;
  }
  double sub(double a, double b) override {
    std::cout << "-> sub(" << a << "," << b << ")\n";
    return a - b;
  }
  double time(double a, double b) override {
    std::cout << "-> time(" << a << "," << b << ")\n";
    return a * b;
  }
  double div(double a, double b) override {
    std::cout << "-> div(" << a << "," << b << ")\n";
    return a / b;
  }
};

class CalInterface2 : public Calculator {
public:
  CalInterface2() {}
  virtual ~CalInterface2() {}
  double add(double a, double b) override {
    std::cout << "-> add2(" << a << "," << b << ")\n";
    return 1 + a + b;
  }
  double sub(double a, double b) override {
    std::cout << "-> sub2(" << a << "," << b << ")\n";
    return 1 + a - b;
  }
  double time(double a, double b) override {
    std::cout << "-> time2(" << a << "," << b << ")\n";
    return 1 + a * b;
  }
  double div(double a, double b) override {
    std::cout << "-> div2(" << a << "," << b << ")\n";
    return 1 + a / b;
  }
};

class CalInterface3 : public test {
public:
  CalInterface3() {}
  virtual ~CalInterface3() {}
   void f0 () override{}

   void f1 (double a) override{}

   void f2 (i8 a) override{}
   void f3 (i16 a) override{}
   void f5 (i32 a) override{}
   void f6 (i64 a) override{}

   void f7 (u8 a) override{}
   void f8 (u16 a) override{}
   void f9 (u32 a) override{}
   void f10 (u64 a) override{}
  void f11 (S1 a) override{}

  i32 a=0;
  i64 b=0;

  i32 get_a()const override{return a;}
  i64 get_b()const override{return b;}

  void set_a(const i32& p_a)override{a=p_a;}
  void set_b(const i64& p_b)override{b=p_b;}
  
  // void f11 (S1 a)override{}
  // void f12 (S2 b)override{}
};


int main(int argc, char *argv[]) {
  Dbus_server serv;

  CalInterface c1;
  CalInterface2 c2;
  CalInterface3 c3;

  serv.set_in("/a", "Cal.a", &c1);
  serv.set_in("/a", "Cal.b", &c1);
  serv.set_in("/b", "Cal.b", &c3);

  serv.set_object_name("Server.app1.Calcul");
  serv.connect();

  while(true){
    serv.step();
  }

  serv.disconnect();

  return 0;
}
