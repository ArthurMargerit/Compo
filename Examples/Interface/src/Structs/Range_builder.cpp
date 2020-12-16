
#include "Structs/Range_builder.hpp"
#include "Structs/Range_fac.hpp"

Range_builder::Range_builder()

    :

      min(),

      max()

{}
Range_builder::~Range_builder() {}

Range_builder &Range_builder::set_min(const double &p_min) {
  this->min = p_min;
  return *this;
}

Range_builder &Range_builder::set_max(const double &p_max) {
  this->max = p_max;
  return *this;
}

void Range_builder::asign(Range &p_Range) {

  p_Range.set_min(this->min);
  p_Range.set_max(this->max);
}

Range Range_builder::build() {
  Range p_this;
  this->asign(p_this);
  return p_this;
}

Range *Range_builder::build_p() {
  Range *p_this = new Range();
  this->asign(*p_this);
  return p_this;
}

std::shared_ptr<Range> Range_builder::build_sp() {
  auto p_this = std::make_shared<Range>();
  this->asign(*p_this);
  return p_this;
}
