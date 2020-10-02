#pragma once

#include "Interfaces/I2/I2.hpp"

class I2_i : public I2 {
public:
  i32 get_d1() const override { return d1; }
  void set_d1(const i32& d1) override { this->d1 = d1; }

  i32 get_d2() const override { return d2; }
  void set_d2(const i32& d2) override { this->d2 = d2; }

  I2_i();
  virtual ~I2_i();

  i32 f1(i32 a) override;
  i32 f2(i32 a) override;

private:
  i32 d1;
  i32 d2;
};
