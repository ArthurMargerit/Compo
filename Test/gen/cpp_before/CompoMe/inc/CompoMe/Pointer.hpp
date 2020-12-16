namespace CompoMe {
template<typename T>
  class Pointer {
private:
  T* t;
public:
  Pointer():t(nullptr) {}
  Pointer(T* p_t):t(p_t) {}
  Pointer(const Pointer<T>& p_o):Pointer(p_o.t) {}
  virtual ~Pointer() {}
  T& operator*() {return *this->t;}
  T* operator->() { return this->t; }
  bool operator==(const Pointer<T>&p_other) const {return this->t == p_other.t;}
};
}  // Namespace


