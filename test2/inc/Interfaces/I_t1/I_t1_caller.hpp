#pragma once

#include "Interfaces/I_t1/I_t1.hpp"

#include "Interfaces/Caller.hpp"

#include <string>

class I_t1_caller : public Caller {
private:
  I_t1 &comp;

public:
  I_t1_caller(I_t1 &pcomp);

  bool call(Function_stream &is, Return_stream &os);
  virtual bool call(std::string &name_function, Function_stream &is,
                    Return_stream &os);

private:
  void get_sa(Function_stream &is, Return_stream &os);
  void set_sa(Function_stream &is, Return_stream &os);

  void get_sb(Function_stream &is, Return_stream &os);
  void set_sb(Function_stream &is, Return_stream &os);

  void get_sc(Function_stream &is, Return_stream &os);
  void set_sc(Function_stream &is, Return_stream &os);

  void get_sd(Function_stream &is, Return_stream &os);
  void set_sd(Function_stream &is, Return_stream &os);
};
