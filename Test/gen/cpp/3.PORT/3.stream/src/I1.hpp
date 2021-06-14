class I1_i : public I1 {
public:
  I1_i() {}
  virtual ~I1_i() {}

  virtual void f0() {}
  virtual i32 f1(i32 a) { return a; }
  virtual i32 f2(i32 a, i32 b) { return a + b; }
  virtual i32 f3(i32 a, i32 b, i32 c) { return a + b + c; }

  virtual i32 get_a() const { return this->a_a; }
  virtual void set_a(const i32 &a) { this->a_a = a; }
  virtual i32 get_b() const { return this->a_b; }
  virtual void set_b(const i32 &b) { this->a_b = b; }

private:
  i32 a_a;
  i32 a_b;
};
