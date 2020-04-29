#pragma once

#include "Components/Require_helper.hpp"
template <class T> class Require_helper_multi_t {
  std::vector<Require_helper_t<T>> a_helper;

private:
  //Require_helper_t<T> &operator[](int p_i) { return a_helper.at(p_i); }

public:
  Require_helper_multi_t(){}
  virtual ~Require_helper_multi_t() noexcept {}

  void add(T *p_i){}
  // const Require_helper_t<T> &operator[](int p_i) const {}
};
