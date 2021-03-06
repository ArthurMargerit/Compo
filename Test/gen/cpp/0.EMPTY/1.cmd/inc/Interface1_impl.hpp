#include "Interfaces/Interface1/Interface1.hpp"

class Interface1_impl : public Interface1 {
public:
  Interface1_impl();
  virtual ~Interface1_impl();
  void f1() override;
  void f2(i32 a, i32 b) override;
  i32 f3(i32 a, i32 b, i32 c) override;
  A f4(A a, A b) override;

  void set_data1(const i32 &data1) override;
  i32 get_data1() const override;

  i32 get_data2() const override;
  void set_data2(const i32 &data2) override;

  A get_data3() const override;
  void set_data3(const A &data3) override;

private:
  i32 data1;
  i32 data2;
  A data3;
};
