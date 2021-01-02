#pragma once

#include "Structs/S/S2.hpp"

#include <memory>

namespace S {

class S2_builder {

public:
  S2_builder();
  virtual ~S2_builder();

  // setter

  S2_builder &set_s(const S1 &p_s);

  // build
  S2 build();
  S2 *build_p();
  std::shared_ptr<S2> build_sp();

protected:
  void asign(S2 &p_name);

private:
  S1 s;
};

} // namespace S
