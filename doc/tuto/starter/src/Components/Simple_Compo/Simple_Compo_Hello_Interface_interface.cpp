
#include "Components/Simple_Compo/Simple_Compo_Hello_Interface_interface.hpp"
#include "Components/Simple_Compo/Simple_Compo.hpp"

namespace Simple_Compo {

Hello_Interface_interface::Hello_Interface_interface(Simple_Compo *comp)
    : composant(comp) {
  return;
}

//! Destructor
Hello_Interface_interface::~Hello_Interface_interface() noexcept { return; }

// //! Move assignment operator
// interface& interface::operator=(interface &&other) noexcept
//                       {

//                       }
void Hello_Interface_interface::hello_word() { return; }

}; // namespace Simple_Compo
