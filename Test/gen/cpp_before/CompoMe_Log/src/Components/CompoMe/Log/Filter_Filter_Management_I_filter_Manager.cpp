

#include "Components/CompoMe/Log/Filter_Filter_Management_I_filter_Manager.hpp"
#include "Components/CompoMe/Log/Filter.hpp"

namespace CompoMe {

namespace Log {

Filter_Filter_Management_I_filter_Manager::
    Filter_Filter_Management_I_filter_Manager(Filter *comp)
    : composant(comp) {
  return;
}

//! Destructor
Filter_Filter_Management_I_filter_Manager::
    ~Filter_Filter_Management_I_filter_Manager() noexcept {
  return;
}

Filter &Filter_Filter_Management_I_filter_Manager::get_c() const {
  return *this->composant;
}

} // namespace Log

} // namespace CompoMe
