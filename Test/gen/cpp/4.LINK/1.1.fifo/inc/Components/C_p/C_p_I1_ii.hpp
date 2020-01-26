#pragma once

#include "Data/base.hpp"

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

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // I1 /////////////////////////////////////////////////////////
  virtual void f1() override;
  virtual int f3() override;
  virtual void f2(int p1) override;
  virtual int f4(int p1) override;
  virtual int f5(int p1, int p2) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // I1 ///////////////////////////////////////////////////////////////////
  // get/set a
  int get_a() const override;
  void set_a(const int &a) override;
  // get/set b
  int get_b() const override;
  void set_b(const int &b) override;

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
  int a;
  int b;
};
} // namespace C_p