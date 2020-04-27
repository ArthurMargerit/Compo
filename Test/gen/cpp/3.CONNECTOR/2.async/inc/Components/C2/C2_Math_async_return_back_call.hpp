#pragma once

#include "Data/b.hpp"
#include "Interfaces/Math_async_return/Math_async_return.hpp"

namespace C2 {

class C2;

class Math_async_return_back_call : public ::Math_async_return {
public:
  C2 *composant;

  //! Default constructor
  Math_async_return_back_call(C2 *comp);

  //! Destructor
  virtual ~Math_async_return_back_call() noexcept;

  Math_async_return_back_call() = delete;
  //! Copy constructor
  Math_async_return_back_call(const Math_async_return_back_call &other) =
      delete;
  //! Move constructor
  Math_async_return_back_call(Math_async_return_back_call &&other) = delete;
  // //! Copy assignment operator
  // Math_async_return& operator=(const Math_async_return &other)=delete;
  // //! Move assignment operator
  // Math_async_return& operator=(Math_async_return &&other) noexcept;

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
} // namespace C2
