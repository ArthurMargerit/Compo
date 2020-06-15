#pragma once

#include <iostream>
#include <memory>
#include <ostream>

#include "Data/Struct.hpp"

#include "Data/string.hpp"

#include "Data/string.hpp"

#include "Data/File.hpp"

class User : public Struct {
public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////

  User();

  virtual ~User();

  User(int p_id, string p_first_name, string p_last_name, double p_score,
       File p_profile_img);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  int get_id() const;
  void set_id(const int &);
  int &a_id();
  string get_first_name() const;
  void set_first_name(const string &);
  string &a_first_name();
  string get_last_name() const;
  void set_last_name(const string &);
  string &a_last_name();
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

  std::ostream &to_stream(std::ostream &os,
                          Serialization_context_export &p_ctx) const override;
  std::istream &from_stream(std::istream &is,
                            Serialization_context_import &p_ctx) override;

private:
  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  int id;
  string first_name;
  string last_name;
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
