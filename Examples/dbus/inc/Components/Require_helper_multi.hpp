#pragma once

#include "Components/Require_helper.hpp"
template <class T> class Require_helper_multi_t {
  std::vector<Require_helper_t<T>> a_helper;

private:

public:
  Require_helper_multi_t(){}
  virtual ~Require_helper_multi_t() noexcept {}

  void add(T *p_i){
    auto l_i = Require_helper_t<T>(p_i);
    this->a_helper.push_back(l_i);
  }
  Require_helper_t<T> &operator[](int p_i) { return a_helper.at(p_i); }
};