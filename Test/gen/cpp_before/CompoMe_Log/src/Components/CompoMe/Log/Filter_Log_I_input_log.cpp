

#include "Components/CompoMe/Log/Filter_Log_I_input_log.hpp"
#include "Components/CompoMe/Log/Filter.hpp"

namespace CompoMe {

namespace Log {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Filter_Log_I_input_log::Filter_Log_I_input_log(Filter *comp) : composant(comp) {
  return;
}

//! Destructor
Filter_Log_I_input_log::~Filter_Log_I_input_log() noexcept { return; }

Filter &Filter_Log_I_input_log::get_c() const { return *this->composant; }

void Filter_Log_I_input_log::error(CompoMe::String mess,
                                   CompoMe::Log::Log_Info i) {

  void();

  return;
}
void Filter_Log_I_input_log::warning(CompoMe::String mess,
                                     CompoMe::Log::Log_Info i) {

  void();

  return;
}
void Filter_Log_I_input_log::debug(CompoMe::String mess,
                                   CompoMe::Log::Log_Info i) {

  void();

  return;
}
void Filter_Log_I_input_log::info(CompoMe::String mess,
                                  CompoMe::Log::Log_Info i) {

  void();

  return;
}
void Filter_Log_I_input_log::log(CompoMe::Log::Kind_e k, CompoMe::String mess,
                                 CompoMe::Log::Log_Info i) {

  void();

  return;
}

// Log_I ///////////////////////////////////////////////////////////////////

std::ostream &Filter_Log_I_input_log::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "CompoMe::Log::Filter_Log_I_input_log";

  os << "}";
  return os;
}

std::istream &Filter_Log_I_input_log::from_stream(
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
      if (t.first != "CompoMe::Log::Filter_Log_I_input_log") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide Filter_Log_I_input_log";
      throw "wrong attribute: \"" + args +
          "\" not in provide Filter_Log_I_input_log";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace Log

} // namespace CompoMe
