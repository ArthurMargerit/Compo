#pragma once

#include "Data/b.hpp"
#include "Interfaces/Math_async_return/Math_async_return.hpp"

class C2;

class C2_Math_async_return_back_call : public ::Math_async_return {
public:
  C2 *composant;

  //! Default constructor
  C2_Math_async_return_back_call(C2 *comp);

  //! Destructor
  virtual ~C2_Math_async_return_back_call() noexcept;

  C2_Math_async_return_back_call() = delete;
  //! Copy constructor
  C2_Math_async_return_back_call(const C2_Math_async_return_back_call &other) =
      delete;
  //! Move constructor
  C2_Math_async_return_back_call(C2_Math_async_return_back_call &&other) =
      delete;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Math_async_return /////////////////////////////////////////////////////////
  virtual void ping(int p_ping) override;
  virtual void f1(int p_f1) override;
  virtual void f2(int p_f2) override;
  virtual void f3() override;
  virtual void get_a(int p_a) override;
  virtual void set_a() override;
  virtual void get_b(int p_b) override;
  virtual void set_b() override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Math_async_return
  // ///////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  //                            SAVE/LOAD                                  //
  ///////////////////////////////////////////////////////////////////////////
  void save(std::ostream &os) const;
  void load(std::istream &is);

private:
  C2 &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Math_async_return
};