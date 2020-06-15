

#include "Components/Car/Gates/controller_Window_win.hpp"
#include "Components/Car/Gates/controller.hpp"

namespace Car {

namespace Gates {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

controller_Window_win::controller_Window_win(controller *comp)
    : composant(comp), percent() {
  return;
}

//! Destructor
controller_Window_win::~controller_Window_win() noexcept { return; }

controller &controller_Window_win::get_c() const { return *this->composant; }

void controller_Window_win::lock() {

  void();

  return;
}
void controller_Window_win::unlock() {

  void();

  return;
}

// Window ///////////////////////////////////////////////////////////////////
// get/set percent
ui8 controller_Window_win::get_percent() const { return this->percent; }

void controller_Window_win::set_percent(const ui8 &percent) {

  this->percent = percent;
}

std::ostream &
controller_Window_win::to_stream(std::ostream &os,
                                 Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "Car::Gates::controller_Window_win";

  os << ",percent:" << this->get_percent();

  os << "}";
  return os;
}

std::istream &
controller_Window_win::from_stream(std::istream &is,
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
      if (t.first != "Car::Gates::controller_Window_win") {
        throw "Wrong Type: ";
      }
      break;
    }

    case str2int("percent"):
      is >> this->percent;
      break;

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide controller_Window_win";
      throw "wrong attribute: \"" + args +
          "\" not in provide controller_Window_win";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace Gates

} // namespace Car
