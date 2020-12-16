
#include "Structs/S2_builder.hpp"
#include "Structs/S2_fac.hpp"

S2_builder::S2_builder()

    :

      i1(),

      i2()

{}
S2_builder::~S2_builder() {}

S2_builder &S2_builder::set_i1(const i32 &p_i1) {
  this->i1 = p_i1;
  return *this;
}

S2_builder &S2_builder::set_i2(const i32 &p_i2) {
  this->i2 = p_i2;
  return *this;
}

void S2_builder::asign(S2 &p_S2) {

  p_S2.set_i1(this->i1);
  p_S2.set_i2(this->i2);
}

S2 S2_builder::build() {
  S2 p_this;
  this->asign(p_this);
  return p_this;
}

S2 *S2_builder::build_p() {
  S2 *p_this = new S2();
  this->asign(*p_this);
  return p_this;
}

std::shared_ptr<S2> S2_builder::build_sp() {
  auto p_this = std::make_shared<S2>();
  this->asign(*p_this);
  return p_this;
}
