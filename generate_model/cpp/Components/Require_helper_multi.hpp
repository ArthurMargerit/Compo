#pragma once

#include "Components/Require_helper.hpp"
#include <iterator>

namespace CompoMe {

template <class T> class Require_helper_multi_t {
private:
  std::vector<Require_helper_t<T>> a_helper;

public:
  Require_helper_multi_t() {}
  virtual ~Require_helper_multi_t() noexcept {}

  void add(T *p_i) {
    auto l_i = Require_helper_t<T>(p_i);
    this->a_helper.push_back(l_i);
  }

  std::size_t size() { return a_helper.size(); }

  typename std::vector<Require_helper_t<T>>::iterator begin() noexcept { return this->a_helper.begin(); }
  typename std::vector<Require_helper_t<T>>::const_iterator begin() const noexcept { return this->a_helper.begin(); }

  typename std::vector<Require_helper_t<T>>::iterator end() noexcept { return this->a_helper.end(); }
  typename std::vector<Require_helper_t<T>>::const_iterator end() const noexcept { return this->a_helper.end(); }

  Require_helper_t<T> &operator[](int p_i) { return a_helper.at(p_i); }
};

} // namespace CompoMe
