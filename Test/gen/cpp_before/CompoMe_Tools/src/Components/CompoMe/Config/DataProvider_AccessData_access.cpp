

#include "Components/CompoMe/Config/DataProvider_AccessData_access.hpp"
#include "Components/CompoMe/Config/DataProvider.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Config {

DataProvider_AccessData_access::DataProvider_AccessData_access(
    DataProvider *comp)
    : composant(comp) {
  return;
}

//! Destructor
DataProvider_AccessData_access::~DataProvider_AccessData_access() noexcept {
  return;
}

DataProvider &DataProvider_AccessData_access::get_c() const {
  return *this->composant;
}

} // namespace Config

} // namespace CompoMe
