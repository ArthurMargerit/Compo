#include "Interfaces/Temperature_report_i/Temperature_report_i_fake.hpp"

Temperature_report_i_fake::Temperature_report_i_fake(Function_stream &out,
                                                     Return_stream &in)
    : Fake(out, in) {}

Temperature_report_i_fake::~Temperature_report_i_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function Temperature_report_i
// ////////////////////////////////////////////////

void Temperature_report_i_fake::notify(Temperature_sample ts) {
  o.start();
  o << "notify("

    << ts

    << ")";
  o.call();

  i.pull();
}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set Temperature_report_i
// /////////////////////////////////////////////////