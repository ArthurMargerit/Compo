#pragma once

#include "Components/Component.hpp"

// TYPE
#include "Data/Types.hpp"

// STRUCT

// INTERFACES

#include "Components/File_logger_c/File_logger_c_Log_i_log.hpp"

namespace File_logger_c {

class File_logger_c : public Component {
public:
  // interface ////////////////////////////////////////////////////////////////
  // Receptacle

  Log_i_log log;

  // Facette

  // c++ 11 def
  //! construction
  File_logger_c();

  //! Copy constructor
  File_logger_c(const File_logger_c &other) = delete;

  //! Move constructor
  File_logger_c(File_logger_c &&other) = delete;

  //! Destructor
  virtual ~File_logger_c() noexcept;

  //! Copy assignment operator
  File_logger_c &operator=(const File_logger_c &other) = delete;

  //! Move assignment operator
  File_logger_c &operator=(File_logger_c &&other) noexcept = delete;

  // composant initialisation
  virtual void configuration();

  virtual void connection();

  virtual void start();

  virtual void stop();

  virtual void step();

  virtual void status();

  // GET SET

  String get_file_path() const { return file_path; }

  void set_file_path(const String file_path) { this->file_path = file_path; }

  Log_print_e get_format() const { return format; }

  void set_format(const Log_print_e format) { this->format = format; }

  // function

private:
  String file_path;

  Log_print_e format;

protected:
};
} // namespace File_logger_c