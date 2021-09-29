#include "Types/CompoMe/String_d.hpp"
#include "nlohmann/json.hpp"

namespace nlohmann {
template <> struct adl_serializer<CompoMe::String> {
  static void to_json(json &j, const CompoMe::String &value) { j = value.str; }

  static void from_json(const json &j, CompoMe::String &value) {
    j.get_to(value.str);
  }
};
} // namespace nlohmann
