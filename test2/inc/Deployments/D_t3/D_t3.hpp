#pragma once

#include "Deployments/D_t2/D_t2.hpp"

#include "Components/C_t2r/C_t2r.hpp"

#include "Components/C_t2r/C_t2r.hpp"

#include "Components/C_t1r/C_t1r.hpp"

#include "Components/C_n/C_n.hpp"

#include "Links/Simple/Simple.hpp"

#include "Links/Out_link/Out_link.hpp"

#include "Links/In_link/In_link.hpp"

class D_t3 : public D_t2 {
private:
  C_t2r::C_t2r r2;

  C_t2r::C_t2r r3;

  C_t1r::C_t1r r4;

  C_n::C_n r5;

  Simple s1;

  Simple s2;

  Simple s3;

  Simple s4;

  Out_link lo1;

  Out_link lo2;

  In_link li1;

  In_link li2;

public:
  D_t3();
  virtual ~D_t3();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();

  C_t2r::C_t2r &get_r2();

  C_t2r::C_t2r &get_r3();

  C_t1r::C_t1r &get_r4();

  C_n::C_n &get_r5();
};