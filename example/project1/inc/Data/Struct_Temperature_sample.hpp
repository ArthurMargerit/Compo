#pragma once

#include <ostream>

#include "Data/temperature_sensors.hpp"

#include "Data/Struct.hpp"

#include "Data/Struct_Vec3.hpp"

struct Temperature_sample : public Struct {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  double val;
  Vec3 pos;
  String place;

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  Temperature_sample();

  Temperature_sample(double p_val, Vec3 p_pos, String p_place);

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  double get_val() const;

  void set_val(const double value);
  Vec3 get_pos() const;

  void set_pos(const Vec3 value);
  String get_place() const;

  void set_place(const String value);

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////

  virtual void to_stream(std::ostream &) const;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream &operator<<(std::ostream &os, const Temperature_sample &c);
std::istream &operator>>(std::istream &os, Temperature_sample &c);

std::ostream &operator<<(std::ostream &os, const Temperature_sample *c);
std::istream &operator>>(std::istream &os, Temperature_sample *&c);
