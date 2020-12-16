#pragma once

#include "Data/CompoMe_Log.hpp"
#include "Interfaces/CompoMe/Log/Filter_Management_I/Filter_Management_I.hpp"

#include "Serialization_context.hpp"

namespace CompoMe {

namespace Log {

class Filter;

class Filter_Filter_Management_I_filter_Manager
    : public ::CompoMe::Log::Filter_Management_I {
public:
  Filter *composant;

  //! Default constructor
  Filter_Filter_Management_I_filter_Manager(Filter *comp);

  //! Destructor
  virtual ~Filter_Filter_Management_I_filter_Manager() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Filter_Management_I
  // /////////////////////////////////////////////////////////
  virtual void add(CompoMe::Log::Kind_e k) override;
  virtual void del(CompoMe::Log::Kind_e k) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Filter_Management_I
  // ///////////////////////////////////////////////////////////////////

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
  Filter &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Filter_Management_I
};

} // namespace Log

} // namespace CompoMe
