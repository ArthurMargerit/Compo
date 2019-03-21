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
  Pos get_position() const;

  void set_position(const Pos value);
  Dot get_Size() const;

  void set_Size(const Dot value);
  Dot get_Size2() const;

  void set_Size2(const Dot value);
  int get_a() const;

  void set_a(const int value);
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const square& c);
std::istream& operator>>(std::istream& os,square& c);
