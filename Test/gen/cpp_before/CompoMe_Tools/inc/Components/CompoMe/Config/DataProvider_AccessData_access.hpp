#pragma once

#include "Data/CompoMe_Tools.hpp"
#include "Interfaces/CompoMe/Config/AccessData/AccessData.hpp"

#include "Serialization_context.hpp"

namespace CompoMe {

namespace Config {

class DataProvider;

class DataProvider_AccessData_access : public ::CompoMe::Config::AccessData {
public:
  DataProvider *composant;

  //! Default constructor
  DataProvider_AccessData_access(DataProvider *comp);

  //! Destructor
  virtual ~DataProvider_AccessData_access() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // AccessData /////////////////////////////////////////////////////////
  virtual CompoMe::Config::Result_state add(CompoMe::String key,
                                            CompoMe::String value) override;
  virtual CompoMe::Config::Result_state set(CompoMe::String key,
                                            CompoMe::String value) override;
  virtual CompoMe::Config::Result_state del(CompoMe::String key) override;
  virtual CompoMe::Config::Result_get get(CompoMe::String key) override;
  virtual bool exist(CompoMe::String key) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // AccessData
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
  DataProvider &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for AccessData
};

} // namespace Config

} // namespace CompoMe
