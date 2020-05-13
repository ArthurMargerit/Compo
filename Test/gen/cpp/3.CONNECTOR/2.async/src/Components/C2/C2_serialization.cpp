#include "Components/C2/C2.hpp"
#include "Serialization_context.hpp"
#include <iostream>

namespace C2 {

std::ostream &operator<<(std::ostream &os, const C2 &c) {
  Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, C2 &c) {
  Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
std::ostream &C2::to_stream(std::ostream &os,
                            Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "C2";

  os << ",provide:{";

  os << "back_call:";
  this->back_call.save(os);

  os << "}"; // // os << ",require:{";
  //
  // os << "call:" << this->call;
  // //
  // os << "}";
  //// os << "}";
  return os;
}

std::istream &C2::from_stream(std::istream &is,
                              Serialization_context_import &p_ctx) {
  // TODO
  return is;
}

} // namespace C2
