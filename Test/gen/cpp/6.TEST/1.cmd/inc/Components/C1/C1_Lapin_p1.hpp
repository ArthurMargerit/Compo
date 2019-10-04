#pragma once

#include "Data/exist.hpp"

#include "Interfaces/Lapin/Lapin.hpp"

namespace C1 {

class C1;

class Lapin_p1 : public ::Lapin {
public:
  C1 *composant;

  //! Default constructor
  Lapin_p1(C1 *comp);

  //! Destructor
  virtual ~Lapin_p1() noexcept;

  Lapin_p1() = delete;
  //! Copy constructor
  Lapin_p1(const Lapin_p1 &other) = delete;
  //! Move constructor
  Lapin_p1(Lapin_p1 &&other) = delete;
  // //! Copy assignment operator
  // Lapin& operator=(const Lapin &other)=delete;
  // //! Move assignment operator
  // Lapin& operator=(Lapin &&other) noexcept;

  C1 &get_c() const { return *this->composant; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Lapin /////////////////////////////////////////////////////////
  virtual int add(int a, int b);
  virtual int sub(int a, int b);
  virtual int time(int a, int b);
  virtual int div(int a, int b);

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Lapin ///////////////////////////////////////////////////////////////////

private:
  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Lapin
};
};