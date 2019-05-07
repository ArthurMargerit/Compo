#pragma once

#include <ostream>

#include "Data/Types.hpp"
#include "Data/Types_e.hpp"
#include "Data/Struct.hpp"

struct Log_s : public Struct {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  Log_e type_log;
  String message;
  String file;
  ui32 line;
  String module_type;
  String module_name;
  String function_name;

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  Log_s();

  Log_s(Log_e p_type_log, String p_message, String p_file, ui32 p_line,
        String p_module_type, String p_module_name, String p_function_name);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  Log_e get_type_log() const;

  void set_type_log(const Log_e value);
  String get_message() const;

  void set_message(const String value);
  String get_file() const;

  void set_file(const String value);
  ui32 get_line() const;

  void set_line(const ui32 value);
  String get_module_type() const;

  void set_module_type(const String value);
  String get_module_name() const;

  void set_module_name(const String value);
  String get_function_name() const;

  void set_function_name(const String value);

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////
  virtual void print(Log_print_e p);

  virtual void to_stream(std::ostream &) const;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream &operator<<(std::ostream &os, const Log_s &c);
std::istream &operator>>(std::istream &os, Log_s &c);

std::ostream &operator<<(std::ostream &os, const Log_s *c);
std::istream &operator>>(std::istream &os, Log_s *&c);
