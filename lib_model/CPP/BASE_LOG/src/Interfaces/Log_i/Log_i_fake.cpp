#include "Interfaces/Log_i/Log_i_fake.hpp"

Log_i_fake::Log_i_fake(Function_stream &out, Return_stream &in)
    : o(out), i(in) {}

Log_i_fake::~Log_i_fake() noexcept {}
void Log_i_fake::info(String mess) {
  o.start();
  o << "info("

    << mess

    << ")";
  o.call();

  i.pull();
}
void Log_i_fake::debug(String mess) {
  o.start();
  o << "debug("

    << mess

    << ")";
  o.call();

  i.pull();
}
void Log_i_fake::warning(String mess) {
  o.start();
  o << "warning("

    << mess

    << ")";
  o.call();

  i.pull();
}
void Log_i_fake::error(String mess) {
  o.start();
  o << "error("

    << mess

    << ")";
  o.call();

  i.pull();
}
void Log_i_fake::log(Log_s mess) {
  o.start();
  o << "log("

    << mess

    << ")";
  o.call();

  i.pull();
}