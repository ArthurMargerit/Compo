

#include "Components/Car/Gates/controller_Locker_locker.hpp"
#include "Components/Car/Gates/controller.hpp"

namespace Car {

namespace Gates {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

controller_Locker_locker::controller_Locker_locker(controller *comp)
    : composant(comp) {
  return;
}

//! Destructor
controller_Locker_locker::~controller_Locker_locker() noexcept { return; }

controller &controller_Locker_locker::get_c() const { return *this->composant; }

void controller_Locker_locker::open_window() {

  void();

  return;
}
void controller_Locker_locker::close_window() {

  void();

  return;
}
string controller_Locker_locker::state() {

  string ret =

      string();

  return ret;
}

// Locker ///////////////////////////////////////////////////////////////////

std::ostream &
controller_Locker_locker::to_stream(std::ostream &os,
                                    Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "Car::Gates::controller_Locker_locker";

  os << "}";
  return os;
}

std::istream &
controller_Locker_locker::from_stream(std::istream &is,
                                      Serialization_context_import &p_ctx) {
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
      auto t = get_word(is, {',', '}'});
      if (t.first != "Car::Gates::controller_Locker_locker") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide controller_Locker_locker";
      throw "wrong attribute: \"" + args +
          "\" not in provide controller_Locker_locker";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace Gates

} // namespace Car
