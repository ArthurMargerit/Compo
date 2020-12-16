#pragma once

#include "Data/file.hpp"
#include "Interfaces/Hello_I/Hello_I.hpp"

#include "Serialization_context.hpp"

class HelloWord;

class HelloWord_Hello_I_inter : public ::Hello_I {
public:
  HelloWord *composant;

  //! Default constructor
  HelloWord_Hello_I_inter(HelloWord *comp);

  //! Destructor
  virtual ~HelloWord_Hello_I_inter() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Hello_I /////////////////////////////////////////////////////////
  virtual CompoMe::String hello(CompoMe::String who) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Hello_I ///////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  //                            SAVE/LOAD                                  //
  ///////////////////////////////////////////////////////////////////////////
  // void save(std::ostream& os) const;
  // void load(std::istream& is);
  std::ostream &to_stream(std::ostream &,
                          CompoMe::Serialization_context_export &) const;
  std::istream &from_stream(std::istream &,
                            CompoMe::Serialization_context_import &);

private:
  HelloWord &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Hello_I
};
