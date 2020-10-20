#pragma once

#include <istream>
#include <ostream>

#include <tuple>

template <typename... Args> using Tuple = std::tuple<Args...>;

namespace std {
  namespace {
    // printer of tuple ////////////////////////////////////////////////////////
    template<typename T>
     struct tuple_print {
    public:
      template<unsigned int n,unsigned int l>
      struct ts {
      public:
        static void st(std::ostream &os, const T &p) {
          os << std::get<n>(p)<<",";
          ts<n+1,l>::st(os,p);
        }
      };
      template<unsigned int n>
      struct ts<n,n> {
      public:
        static void st(std::ostream &os, const T &p) {
          os << std::get<n>(p);
        }
      };
      static void print(std::ostream &os, const T &p) {
        ts<0,std::tuple_size<T>::value-1>::st(os,p);
      }
    };
    template<>
    struct tuple_print<std::tuple<>> {
      static void print(std::ostream &os, const std::tuple<> &p) {}
    };

    // READER of tuple ////////////////////////////////////////////////////////
    template<typename T>
    struct tuple_reader {
    public:
      template<unsigned int n,unsigned int l>
      struct ts {
      public:
        static void st(std::istream &is, T &p) {
          is >> std::get<n>(p);
          is.get();
          ts<n+1,l>::st(is,p);
        }
      };
      template<unsigned int n>
      struct ts<n,n> {
      public:
        static void st(std::istream &is, T &p) {
          is >> std::get<n>(p);
        }
      };
      static void read(std::istream &is,  T &p) {
        ts<0,std::tuple_size<T>::value-1>::st(is,p);
      }
    };

    template<>
    struct tuple_reader<std::tuple<>> {
      static void read(std::istream &is, std::tuple<> &p) {}
    };
  }


template <typename... Args>
std::ostream &operator<<(std::ostream &os, const Tuple<Args...> &p) {
  os << "<";
  tuple_print<Tuple<Args...>>::print(os,p);
  os << ">";
  return os;

}

template <typename... Args>
std::istream &operator>>(std::istream &is, Tuple<Args...> &p) {
  if(is.peek() != '<'){
    return is;
  }
  is.get();

  tuple_reader<Tuple<Args...>>::read(is,p);

  if(is.peek() != '>'){
    return is;
  }
  is.get();
  return is;
}
} // namespace std
