#include "Interfaces/I4Introspection_func/I4Introspection_func.hpp"
#include "Interfaces/I4Introspection_getset/I4Introspection_getset.hpp"
#include "Interfaces/IA/IA.hpp"
#include "Interfaces/IB/IB.hpp"
#include "Interfaces/IC/IC.hpp"
#include <iostream>

class IA_i : public IA {
  i32 a1, a2, a3;

public:
  IA_i() : a1(0), a2(0), a3(0) {}
  virtual ~IA_i() {}
  i32 get_a1() const override { return a1; }
  void set_a1(const i32 &p_a1) override { a1 = p_a1; }
  i32 get_a2() const override { return a2; }
  void set_a2(const i32 &p_a2) override { a2 = p_a2; }
  i32 get_a3() const override { return a3; }
  void set_a3(const i32 &p_a3) override { a3 = p_a3; }
};

class IB_i : public IB {
public:
  IB_i() {}
  virtual ~IB_i() {}

  void f0() {}
  i32 f1() { return 42; }
  i32 f2(i32 p1) { return p1; }
  i32 f3(i32 p1, i32 p2) {
    std::cout << ">" << p1 << "," << p2 << "<\n";
    return p1 + p2;
  }
  i32 f4(i32 p1, i32 p2, i32 p3) { return p1 + p2 + p3; }
};

class IC_i : public IC {
public:
  IC_i() {}
  virtual ~IC_i() {}
  S1 f0() override {
    S1 l(4, 9, 16);
    return l;
  }

  void f1(S1 a) override {}

  S1 f2(S1 b) override {
    b.set_a(b.get_a() + 1);
    b.set_b(b.get_b() + 1);
    b.set_c(b.get_c() + 1);
    return b;
  }

  S1 f3(S1 a, S1 b) override {
    std::cout << a.get_a() << "|" << b.get_a() << "\n";
    S1 c(a.get_a() + b.get_a(), a.get_b() + b.get_b(), a.get_c() + b.get_c());
    return c;
  }
};

class I4Introspection_func_i : public I4Introspection_func {
  void myfunc() override {}
};

class I4Introspection_getset_i : public I4Introspection_getset {
  i32 get_mydata() const override { return 0; }
  void set_mydata(const i32 &) override {}
};
