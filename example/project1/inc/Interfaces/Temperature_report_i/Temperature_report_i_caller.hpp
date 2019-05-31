#pragma once

#include "Interfaces/Temperature_report_i/Temperature_report_i.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class Temperature_report_i_caller : public Caller {
private:
  Temperature_report_i &comp;

public:
  Temperature_report_i_caller(Temperature_report_i &pcomp);

  bool call(Function_stream &is, Return_stream &os);
  virtual bool call(std::string &name_function, Function_stream &is,
                    Return_stream &os);

private:
  void notify(Function_stream &is, Return_stream &os);
};
