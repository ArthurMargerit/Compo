#pragma once

class {{name}}
{
 public:
  // Interface

  // in

  // out


  // c++ 11 def
  //! construction
  {{name}}();

  //! Copy constructor
  {{name}}(const {{name}} &other);

  //! Move constructor
  {{name}}({{name}} &&other) noexcept;

  //! Destructor
  virtual ~{{name}}() noexcept;

  //! Copy assignment operator
  {{name}}& operator=(const {{name}} &other);

  //! Move assignment operator
  {{name}}& operator=({{name}} &&other) noexcept;


  // composant initialisation
  void configuration();

  void connection();

  void start();

  void stop();

  void status();

 private:

 protected:

};
