#pragma once

#include <ostream>

#include "Data/Types.hpp"

#include "Data/Struct.hpp"










struct C : public Struct {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  int a;
  int b;
  int c;

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  C();

  

  C(int p_a,int p_b,int p_c);
  

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  // a
  int get_a() const {
    return this->a;
  }

  void set_a(const int value) {
    this->a = value;
  }
  // b
  int get_b() const {
    return this->b;
  }

  void set_b(const int value) {
    this->b = value;
  }
  // c
  int get_c() const {
    return this->c;
  }

  void set_c(const int value) {
    this->c = value;
  }
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const C& c);
std::istream& operator>>(std::istream& os,C& c);
