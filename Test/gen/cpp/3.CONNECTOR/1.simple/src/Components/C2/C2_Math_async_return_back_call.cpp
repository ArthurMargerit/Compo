
#include "Components/C2/C2_Math_async_return_back_call.hpp"
#include "Components/C2/C2.hpp"

namespace C2 {

Math_async_return_back_call::Math_async_return_back_call(C2 *comp)
    : composant(comp) {
  return;
}

//! Destructor
Math_async_return_back_call::~Math_async_return_back_call() noexcept { return; }

C2 &Math_async_return_back_call::get_c() const { return *this->composant; }

void Math_async_return_back_call::ping(int p_ping) {

  void();
  return;
}
void Math_async_return_back_call::f1(int p_f1) {

  void();
  return;
}
void Math_async_return_back_call::f2(int p_f2) {

  void();
  return;
}
void Math_async_return_back_call::f3() {

  void();
  return;
}
void Math_async_return_back_call::get_a(int p_a) {

  void();

  return;
}
void Math_async_return_back_call::set_a() {

  void();
  this->get_c().call->get_a();

  return;
}
void Math_async_return_back_call::get_b(int p_b) {

  void();

  return;
}
void Math_async_return_back_call::set_b() {

  void();
  this->get_c().call->get_b();

  return;
}

// Math_async_return
// ///////////////////////////////////////////////////////////////////

}; // namespace C2
