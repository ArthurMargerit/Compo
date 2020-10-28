

#include "Components/C_p_I1_ii.hpp"
#include "Components/C_p.hpp"
#include "Errors/E1.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

C_p_I1_ii::C_p_I1_ii(C_p *comp) : composant(comp), a(), b() { return; }

//! Destructor
C_p_I1_ii::~C_p_I1_ii() noexcept { return; }

C_p &C_p_I1_ii::get_c() const { return *this->composant; }

void C_p_I1_ii::f1() {

  void();

  return;
}
int C_p_I1_ii::f2() {

  int ret =

      int();

  return 1;
}
int C_p_I1_ii::f3(int a) {

  int ret =

      int();

  return a+1;
}
int C_p_I1_ii::f4(int a, int b) {

  int ret =

      int();

  return a+b+1;
}

void C_p_I1_ii::call_a_function_that_throw_an_error1() {
  E1 e;
  e.real();
  return;
}

i32 C_p_I1_ii::call_a_function_that_throw_an_error2(i32 a) {
  E1 e;
  e.real();
  return 1;
}

Vec<i32> C_p_I1_ii::call_a_function_that_throw_an_error3(i32 a, CompoMe::String b) {
  E1 e;
  auto s = std::string("Error ")+b.str;
  e.set_msg(s);
  e.set_val(a-1);
  e.real();
  return {1,2,3};
}


// I1 ///////////////////////////////////////////////////////////////////
// get/set a
int C_p_I1_ii::get_a() const { return this->a; }

void C_p_I1_ii::set_a(const int &a) { this->a = a; }
// get/set b
int C_p_I1_ii::get_b() const { return this->b; }

void C_p_I1_ii::set_b(const int &b) { this->b = b; }

std::ostream &C_p_I1_ii::to_stream(std::ostream &os,
                                  CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "C_p_I1_ii";

  os << ",a:" << this->get_a();

  os << ",b:" << this->get_b();

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

    case str2int("a"):
      is >> this->a;
      break;

    case str2int("b"):
      is >> this->b;
      break;

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
