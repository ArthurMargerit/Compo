#include "Data/Types.hpp"

#include "Data/Struct_Log_s.hpp"

#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Log_s *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, Log_s *&c) {
  std::string t = get_type(is);
  if (t != "Log_s"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <Log_s>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Log_s &c) {
  os << "{"
     << "type:"
     << "Log_s,"
     << "type_log:" << c.type_log << ","
     << "message:" << c.message << ","
     << "file:" << c.file << ","
     << "line:" << c.line << ","
     << "module_type:" << c.module_type << ","
     << "module_name:" << c.module_name << ","
     << "function_name:" << c.function_name << "}";
  return os;
}

std::istream &operator>>(std::istream &is, Log_s &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "Log_s") {
    std::cerr << "ERREUR TYPE:"
              << ">Log_s< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.type_log;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.message;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.file;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.line;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.module_type;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.module_name;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.function_name;
  is.ignore(1, '}');

  return is;
}

Log_s::Log_s(Log_e p_type_log, String p_message, String p_file, ui32 p_line,
             String p_module_type, String p_module_name, String p_function_name)
    : type_log(p_type_log), message(p_message), file(p_file), line(p_line),
      module_type(p_module_type), module_name(p_module_name),
      function_name(p_function_name) {}

Log_s::Log_s()
    : type_log(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      message(UNDEF), file(UNDEF), line(0), module_type(UNDEF),
      module_name(UNDEF), function_name(UNDEF) {}
Log_e Log_s::get_type_log() const { return this->type_log; }

void Log_s::set_type_log(const Log_e value) { this->type_log = value; }
String Log_s::get_message() const { return this->message; }

void Log_s::set_message(const String value) { this->message = value; }
String Log_s::get_file() const { return this->file; }

void Log_s::set_file(const String value) { this->file = value; }
ui32 Log_s::get_line() const { return this->line; }

void Log_s::set_line(const ui32 value) { this->line = value; }
String Log_s::get_module_type() const { return this->module_type; }

void Log_s::set_module_type(const String value) { this->module_type = value; }
String Log_s::get_module_name() const { return this->module_name; }

void Log_s::set_module_name(const String value) { this->module_name = value; }
String Log_s::get_function_name() const { return this->function_name; }

void Log_s::set_function_name(const String value) {
  this->function_name = value;
}
void Log_s::print(Log_print_e p) { return; }

void Log_s::to_stream(std::ostream &os) const { os << *this; }