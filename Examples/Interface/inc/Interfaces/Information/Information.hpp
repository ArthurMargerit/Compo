#pragma once

#include "Data/file.hpp"

#include "Interfaces/Interface.hpp"

#include <functional>

class Caller;
class Fake;

class Information_caller;
class Information_fake;
class Information : public Interface {
public:
  using MyCaller = Information_caller;
  using MyFake = Information_fake;

  virtual Caller *get_caller() override;

  //! Default constructor
  Information();

  //! Destructor
  virtual ~Information() noexcept;

  // //! Copy assignment operator
  // Information& operator=(const Information &other){}

  // //! Move assignment operator
  // Information& operator=(Information &&other) noexcept{}
  virtual string get_name() = 0;
  virtual string get_type() = 0;
  virtual string get_location() = 0;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

private:
  Caller *c;
};

// Build_fake_F get_build_fake(Information* t);
