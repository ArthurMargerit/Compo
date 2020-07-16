

#include "Components/C1_Lapin_p1.hpp"
#include "Components/C1.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

C1_Lapin_p1::C1_Lapin_p1(C1 *comp) : composant(comp) { return; }

//! Destructor
C1_Lapin_p1::~C1_Lapin_p1() noexcept { return; }

C1 &C1_Lapin_p1::get_c() const { return *this->composant; }

int C1_Lapin_p1::add(int a, int b) {

  int ret =

      int();

  return ret;
}
int C1_Lapin_p1::sub(int a, int b) {

  int ret =

      int();

  return ret;
}
int C1_Lapin_p1::time(int a, int b) {

  int ret =

      int();

  return ret;
}
int C1_Lapin_p1::div(int a, int b) {

  int ret =

      int();

  return ret;
}

// Lapin ///////////////////////////////////////////////////////////////////

std::ostream &
C1_Lapin_p1::to_stream(std::ostream &os,
                       CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "C1_Lapin_p1";

  os << "}";
  return os;
}

std::istream &
C1_Lapin_p1::from_stream(std::istream &is,
                         CompoMe::Serialization_context_import &p_ctx) {
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
      if (t.first != "C1_Lapin_p1") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide C1_Lapin_p1";
      throw "wrong attribute: \"" + args + "\" not in provide C1_Lapin_p1";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}
