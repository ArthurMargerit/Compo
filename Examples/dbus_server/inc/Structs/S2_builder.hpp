#pragma once

#include "Structs/S2.hpp"

#include <memory>

class S2_builder {

public:
  S2_builder();
  virtual ~S2_builder();

  // setter

  S2_builder &set_i1(const i32 &p_i1);

  S2_builder &set_i2(const i32 &p_i2);

  // build
  S2 build();
  S2 *build_p();
  std::shared_ptr<S2> build_sp();

protected:
  void asign(S2 &p_name);

private:
  i32 i1;

  i32 i2;
};
