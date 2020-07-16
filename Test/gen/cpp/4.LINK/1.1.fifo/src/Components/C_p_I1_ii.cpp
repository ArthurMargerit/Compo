

#include "Components/C_p_I1_ii.hpp"
#include "Components/C_p.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

C_p_I1_ii::C_p_I1_ii(C_p *comp) : composant(comp) { return; }

//! Destructor
C_p_I1_ii::~C_p_I1_ii() noexcept { return; }

C_p &C_p_I1_ii::get_c() const { return *this->composant; }

void C_p_I1_ii::f1() {

  return;
}
int C_p_I1_ii::f2() {

  return 1;
}
int C_p_I1_ii::f3(int a) {


  return a+1;
}
int C_p_I1_ii::f4(int a, int b) {

  return a+b+1;
}

// I1 ///////////////////////////////////////////////////////////////////

std::ostream &C_p_I1_ii::to_stream(std::ostream &os,
                                  CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "C_p_I1_ii";

  os << "}";
  return os;
}

std::istream &C_p_I1_ii::from_stream(std::istream &is,
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
      if (t.first != "C_p_I1_ii") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide C_p_I1_ii";
      throw "wrong attribute: \"" + args + "\" not in provide C_p_I1_ii";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}
