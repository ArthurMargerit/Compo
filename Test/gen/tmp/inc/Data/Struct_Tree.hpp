#pragma once

#include <ostream>

#include "Data/Types.hpp"

#include "Data/Struct.hpp"










struct Tree : public Struct {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  pTree g;
  pTree d;
  ppTree e;

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  Tree();

  

  Tree(pTree p_g,pTree p_d,ppTree p_e);
  

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  // g
  pTree get_g() const {
    return this->g;
  }

  void set_g(const pTree value) {
    this->g = value;
  }
  // d
  pTree get_d() const {
    return this->d;
  }

  void set_d(const pTree value) {
    this->d = value;
  }
  // e
  ppTree get_e() const {
    return this->e;
  }

  void set_e(const ppTree value) {
    this->e = value;
  }
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const Tree& c);
std::istream& operator>>(std::istream& os,Tree& c);
