#include "Interfaces/I_t2/I_t2_fake.hpp"

I_t2_fake::I_t2_fake(Function_stream &out, Return_stream &in)
    : I_t1_fake(out, in) {}

I_t2_fake::~I_t2_fake() noexcept {}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE Function I_t1 //////////////////////////////////////

// INTERFACE Function I_t2 ////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////

// INTERFACE get/set I_t1 ////////////////////////////////////////

A I_t2_fake::get_sa() const { return I_t1_fake::get_sa(); }

void I_t2_fake::set_sa(const A p_sa) { I_t1_fake::set_sa(p_sa); }

B I_t2_fake::get_sb() const { return I_t1_fake::get_sb(); }

void I_t2_fake::set_sb(const B p_sb) { I_t1_fake::set_sb(p_sb); }

C I_t2_fake::get_sc() const { return I_t1_fake::get_sc(); }

void I_t2_fake::set_sc(const C p_sc) { I_t1_fake::set_sc(p_sc); }

D I_t2_fake::get_sd() const { return I_t1_fake::get_sd(); }

void I_t2_fake::set_sd(const D p_sd) { I_t1_fake::set_sd(p_sd); }

// INTERFACE get/set I_t2 /////////////////////////////////////////////////