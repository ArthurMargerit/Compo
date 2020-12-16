

#include "Components/Sensor.hpp"
#include "Components/Sensor_Thermal_Sensor_I_capteur1.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &Sensor_Thermal_Sensor_I_capteur1::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "Sensor_Thermal_Sensor_I_capteur1";

  os << ",ofset:" << this->get_ofset();

  os << "}";
  return os;
}

std::istream &Sensor_Thermal_Sensor_I_capteur1::from_stream(
    std::istream &is, CompoMe::Serialization_context_import &p_ctx) {
  char l_c = is.get();
  if (l_c != '{') {
    std::cerr << "Wrong start: '" << l_c << "' != '{'";
    throw "Wrong start: '"
          "' != '{'";
  }

  do {
    std::string args;
    std::getline(is, args, ':');

    switch (str2int(args.c_str())) {
    case str2int("type"): {
      auto t = CompoMe::get_word(is, {',', '}'});
      if (t.first != "Sensor_Thermal_Sensor_I_capteur1") {
        throw "Wrong Type: ";
      }
      break;
    }

    case str2int("ofset"):
      is >> this->ofset;
      break;

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide Sensor_Thermal_Sensor_I_capteur1";
      throw "wrong attribute: \"" + args +
          "\" not in provide Sensor_Thermal_Sensor_I_capteur1";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}
