#include "Structs/Range.hpp"

// GET SET ////////////////////////////////////////////////////////////////////

// get/set min
double Range::get_min() const { return this->min; }

void Range::set_min(const double &p_min) { this->min = p_min; }

double &Range::a_min() { return this->min; }

// get/set max
double Range::get_max() const { return this->max; }

void Range::set_max(const double &p_max) { this->max = p_max; }

double &Range::a_max() { return this->max; }
