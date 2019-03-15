
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

class Function_stream {

public:
  std::istream *si;
  std::ostream *so;

  std::function<void(void)> f;

  Function_stream(std::iostream *p_s) : si(p_s), so(p_s) {}
  Function_stream(std::istream *p_s) : si(p_s) {}
  Function_stream(std::ostream *p_s) : so(p_s) {}

  virtual ~Function_stream() {}

  virtual void call() {}
  virtual void start() {}
};

class Return_stream {

public:
  std::istream *si;
  std::ostream *so;

  Return_stream(std::iostream *p_s) : si(p_s), so(p_s) {}
  Return_stream(std::istream *p_s) : si(p_s) {}
  Return_stream(std::ostream *p_s) : so(p_s) {}

  virtual ~Return_stream() {}

  virtual void pull() {}
  virtual void end() {}
};

template <typename T>
Function_stream &operator<<(Function_stream &s, const T &e) {
  *s.so << e;
  return s;
}
template <typename T> Function_stream &operator>>(Function_stream &s, T &e) {
  *s.si >> e;
  return s;
}

template <typename T> Return_stream &operator<<(Return_stream &s, const T &e) {
  *s.so << e;
  return s;
}
template <typename T> Return_stream &operator>>(Return_stream &s, T &e) {
  *s.si >> e;
  return s;
}

int main(int argc, char *argv[]) {

  std::stringstream s1;


  std::ifstream fi;
  fi.open("/tmp/d");

  std::ofstream fo;
  fo.open("/tmp/d");

  Function_stream fs(&fo);
  fs.start();
  fs.call();

  Return_stream rs(&fi);
  rs.pull();
  rs.end();

  fs << 1 << 2 << 3;
  fs << "a"
     << "b"
     << "c";
  fs << 'a' << 'b' << 'c';
  fs << 1.0 << 2.0 << 3.0;
  fs << 1.0f << 2.0f << 3.0f;

  return 0;
}
