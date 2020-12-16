#pragma once

#include "Data/CompoMe_Log.hpp"
#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"

#include "Serialization_context.hpp"

namespace CompoMe {

namespace Log {

class Filter;

class Filter_Log_I_input_log : public ::CompoMe::Log::Log_I {
public:
  //! Default constructor
  Filter_Log_I_input_log(Filter *comp);

  //! Destructor
  virtual ~Filter_Log_I_input_log() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Log_I /////////////////////////////////////////////////////////
  virtual void error(CompoMe::String mess, CompoMe::Log::Log_Info i) override;
  virtual void warning(CompoMe::String mess, CompoMe::Log::Log_Info i) override;
  virtual void debug(CompoMe::String mess, CompoMe::Log::Log_Info i) override;
  virtual void info(CompoMe::String mess, CompoMe::Log::Log_Info i) override;
  virtual void log(CompoMe::Log::Kind_e k, CompoMe::String mess,
                   CompoMe::Log::Log_Info i) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Log_I ///////////////////////////////////////////////////////////////////

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
  Filter *composant;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Log_I
};

} // namespace Log

} // namespace CompoMe
