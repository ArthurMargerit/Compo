#pragma once

#include "Data/code.hpp"
#include "Interfaces/I1/I1.hpp"

namespace C_p {

class C_p;

class I1_ii : public ::I1 {
public:
  C_p *composant;

  //! Default constructor
  I1_ii(C_p *comp);

  //! Destructor
  virtual ~I1_ii() noexcept;

  I1_ii() = delete;
  //! Copy constructor
  I1_ii(const I1_ii &other) = delete;
  //! Move constructor
  I1_ii(I1_ii &&other) = delete;
  // //! Copy assignment operator
  // I1& operator=(const I1 &other)=delete;
  // //! Move assignment operator
  // I1& operator=(I1 &&other) noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // I1 /////////////////////////////////////////////////////////
  virtual void f() override;
  virtual void f1() override;
  virtual void f2(i32 a) override;
  virtual void f3(i32 a, i32 b) override;
  virtual i32 f4() override;
  virtual i32 f5(i32 a) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // I1 ///////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  //                            SAVE/LOAD                                  //
  ///////////////////////////////////////////////////////////////////////////
  void save(std::ostream &os) const;
  void load(std::istream &is);

private:
  C_p &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for I1
};
} // namespace C_p
