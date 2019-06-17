#pragma once

#include "Data/Base.hpp"

#include "Interfaces/Ia/Ia.hpp"

namespace C2 {

class C2;

class Ia_b : public ::Ia {
public:
  C2 *composant;

  //! Default constructor
  Ia_b(C2 *comp);

  //! Destructor
  virtual ~Ia_b() noexcept;

  Ia_b() = delete;
  //! Copy constructor
  Ia_b(const Ia_b &other) = delete;
  //! Move constructor
  Ia_b(Ia_b &&other) = delete;
  // //! Copy assignment operator
  // Ia& operator=(const Ia &other)=delete;
  // //! Move assignment operator
  // Ia& operator=(Ia &&other) noexcept;
  virtual int_tt ping(vec<int_tt> p);
  virtual int_tt pp(vec<int_tt> p1, vec<d> p2);
  virtual vec<int_tt> p();

protected:
private:
};

}; // namespace C2