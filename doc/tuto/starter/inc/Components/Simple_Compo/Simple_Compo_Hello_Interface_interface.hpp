#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Hello_Interface/Hello_Interface.hpp"

namespace Simple_Compo {

class Simple_Compo;

class Hello_Interface_interface : public ::Hello_Interface {
public:
  Simple_Compo *composant;

  //! Default constructor
  Hello_Interface_interface(Simple_Compo *comp);

  //! Destructor
  virtual ~Hello_Interface_interface() noexcept;

  Hello_Interface_interface() = delete;
  //! Copy constructor
  Hello_Interface_interface(const Hello_Interface_interface &other) = delete;
  //! Move constructor
  Hello_Interface_interface(Hello_Interface_interface &&other) = delete;
  // //! Copy assignment operator
  // Hello_Interface& operator=(const Hello_Interface &other)=delete;
  // //! Move assignment operator
  // Hello_Interface& operator=(Hello_Interface &&other) noexcept;
  virtual void hello_word();

protected:
private:
};

}; // namespace Simple_Compo