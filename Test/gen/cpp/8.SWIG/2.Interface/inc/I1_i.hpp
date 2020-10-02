#pragma once

#include "Interfaces/I1/I1.hpp"

class I1_i : public I1 {
public:
  i32 get_d1() const override { return d1; }

  void set_d1(const i32& d1) override { this->d1 = d1; }

  I1_i();
  virtual ~I1_i();

  i32 f1(i32 a) override;

private:
  i32 d1;
};
