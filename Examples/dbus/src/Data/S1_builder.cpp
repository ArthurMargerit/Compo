
#include "Data/S1_builder.hpp"
#include "Data/S1_fac.hpp"

S1_builder::S1_builder()

    :

      i1()

{}
S1_builder::~S1_builder() {}

S1_builder &S1_builder::set_i1(const i32 &p_i1) {
  this->i1 = p_i1;
  return *this;
}

void S1_builder::asign(S1 &p_S1) { p_S1.set_i1(this->i1); }

S1 S1_builder::build() {
  S1 p_this;
  this->asign(p_this);
  return p_this;
}

S1 *S1_builder::build_p() {
  S1 *p_this = new S1();
  this->asign(*p_this);
  return p_this;
}

std::shared_ptr<S1> S1_builder::build_sp() {
  auto p_this = std::make_shared<S1>();
  this->asign(*p_this);
  return p_this;
}
