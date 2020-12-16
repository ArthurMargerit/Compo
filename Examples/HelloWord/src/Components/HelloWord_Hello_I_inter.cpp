

#include "Components/HelloWord_Hello_I_inter.hpp"
#include "Components/HelloWord.hpp"

HelloWord_Hello_I_inter::HelloWord_Hello_I_inter(HelloWord *comp)
    : composant(comp) {
  return;
}

//! Destructor
HelloWord_Hello_I_inter::~HelloWord_Hello_I_inter() noexcept { return; }

HelloWord &HelloWord_Hello_I_inter::get_c() const { return *this->composant; }
