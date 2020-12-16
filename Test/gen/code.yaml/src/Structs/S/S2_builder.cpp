
#include "Structs/S/S2_builder.hpp"
#include "Structs/S/S2_fac.hpp"

namespace S {

S2_builder::S2_builder()

    :

      s()

{}
S2_builder::~S2_builder() {}

S2_builder &S2_builder::set_s(const S1 &p_s) {
  this->s = p_s;
  return *this;
}

void S2_builder::asign(S::S2 &p_S2) { p_S2.set_s(this->s); }

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

} // namespace S
