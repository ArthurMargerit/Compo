#pragma once

#include "Structs/Range.hpp"

#include <memory>

class Range_builder {

public:
  Range_builder();
  virtual ~Range_builder();

  // setter

  Range_builder &set_min(const double &p_min);

  Range_builder &set_max(const double &p_max);

  // build
  Range build();
  Range *build_p();
  std::shared_ptr<Range> build_sp();

protected:
  void asign(Range &p_name);

private:
  double min;

  double max;
};
