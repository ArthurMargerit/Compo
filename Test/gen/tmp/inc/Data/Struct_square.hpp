#pragma once

#include <ostream>

#include "Data/Types.hpp"

#include "Data/Struct.hpp"



#include "Data/Struct_Pos.hpp"



#include "Data/Struct_Dot.hpp"









struct square : public Struct {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  Pos position;
  Dot Size;
  Dot Size2;
  int a;

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  square();

  

  square(Pos p_position,Dot p_Size,Dot p_Size2,int p_a);
  

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  // position
  Pos get_position() const {
    return this->position;
  }

  void set_position(const Pos value) {
    this->position = value;
  }
  // Size
  Dot get_Size() const {
    return this->Size;
  }

  void set_Size(const Dot value) {
    this->Size = value;
  }
  // Size2
  Dot get_Size2() const {
    return this->Size2;
  }

  void set_Size2(const Dot value) {
    this->Size2 = value;
  }
  // a
  int get_a() const {
    return this->a;
  }

  void set_a(const int value) {
    this->a = value;
  }
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const square& c);
std::istream& operator>>(std::istream& os,square& c);
