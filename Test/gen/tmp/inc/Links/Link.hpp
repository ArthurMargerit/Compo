#pragma once

#include <string>

class Link
{
public:
  const std::string& get_name_from() const {
    return name_from;
  }

  void set_name_from(const std::string& name_from) {
    this->name_from = name_from;
  }

  const std::string& get_name_to() const {
    return name_to;
  }

  void set_name_to(const std::string& name_to) {
    this->name_to = name_to;
  }

  virtual std::string status()
  {
    return this->get_name_from() + "-(" + this->get_name_type() + ")->" + this->get_name_to();
  }

  virtual std::string get_name_type()=0;


  public:
  //! Default constructor
  Link();

  //! Destructor
  virtual ~Link() noexcept;

  // //! Copy constructor
  // Link(const Link &other) = delete;

  // //! Move constructor
  // Link(Link &&other) noexcept = delete;

  // //! Copy assignment operator
  // Link& operator=(const Link &other) = delete;

  // //! Move assignment operator
  // Link& operator=(Link &&other) noexcept = delete;


private:
  std::string name_to;
  std::string name_from;
};