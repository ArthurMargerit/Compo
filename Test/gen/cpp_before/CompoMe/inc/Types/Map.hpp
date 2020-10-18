#pragma once

#include <istream>
#include <ostream>

#include <map>

template <typename K, typename V> using Map = std::map<K, V>;

namespace std {

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const Map<K, V> & p) {
  os<< "{";
  bool f = false;
  for (auto& i_k_v : p) {
    if(f){
      os << ",";
    }else{
      f = true;
    }

    os << i_k_v.first << ":" << i_k_v.second ;
  }
  os<< "}";

  return os;
}

template <typename K, typename V>
std::istream &operator>>(std::istream &is, Map<K, V> & p) {
  p = Map<K,V>();

  if(is.peek() != '{') {
    return is;
  }
  is.get();

  if(is.peek() == '}') {
    is.get();
    return is;
  }

  do {
    K k;
    V v;
    is >> k;

    if (is.peek() != ':') {
      return is;
    }
    is.get();

    is >> v;

    p[k] = v;
  } while(is.get() != '}');

  return is;
}
} // namespace std
