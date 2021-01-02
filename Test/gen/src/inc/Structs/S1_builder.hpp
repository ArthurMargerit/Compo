#pragma once

#include "Structs/S1.hpp"

#include <memory>

class S1_builder {

public:
  S1_builder();
  virtual ~S1_builder();

  // setter

  S1_builder &set_a(const B::i &p_a);

  // build
  S1 build();
  S1 *build_p();
  std::shared_ptr<S1> build_sp();

protected:
  void asign(S1 &p_name);

private:
  B::i a;
};
