#pragma once

#include "Structs/S1.hpp"

#include <memory>

class S1_builder {

public:
  S1_builder();
  virtual ~S1_builder();

  // setter

  S1_builder &set_i1(const i32 &p_i1);

  // build
  S1 build();
  S1 *build_p();
  std::shared_ptr<S1> build_sp();

protected:
  void asign(S1 &p_name);

private:
  i32 i1;
};
