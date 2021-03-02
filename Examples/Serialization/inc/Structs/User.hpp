#pragma once

#include <memory>
#include <ostream>

#include "Structs/Struct.hpp"

// TYPES

// d.D_NAME

#include "Types/i32.hpp"

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// d.D_NAME

// STRUCTS

class File;

#include "Structs/File.hpp"

struct DBusMessageIter;

class User : public CompoMe::Struct {
public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////

  User();

  virtual ~User();

  User(i32 p_id, CompoMe::String p_first_name, CompoMe::String p_last_name,
       double p_score, File p_profile_img);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  i32 get_id() const;
  void set_id(const i32 &);
  i32 &a_id();
  CompoMe::String get_first_name() const;
  void set_first_name(const CompoMe::String &);
  CompoMe::String &a_first_name();
  CompoMe::String get_last_name() const;
  void set_last_name(const CompoMe::String &);
  CompoMe::String &a_last_name();
  double get_score() const;
  void set_score(const double &);
  double &a_score();
  File get_profile_img() const;
  void set_profile_img(const File &);
  File &a_profile_img();

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const User &other) const;
  bool operator!=(const User &other) const;

  void to_stream(std::ostream &os,
                 CompoMe::Serialization_context_export &p_ctx) const override;
  void from_stream(std::istream &is,
                   CompoMe::Serialization_context_import &p_ctx) override;

private:
  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  i32 id;
  CompoMe::String first_name;
  CompoMe::String last_name;
  double score;
  File profile_img;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream &operator<<(std::ostream &os, const User &c);
std::istream &operator>>(std::istream &os, User &c);
///////////////////////////////////////////////////////////////////////////////
