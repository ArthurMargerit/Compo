{%set CLS_I_NAME = NAME+"_"+i.NAME %}

{{CLS_I_NAME}}::{{CLS_I_NAME}}({{D_NAME}}* p_lo):{{i.D_NAME}}(),a_c(p_lo) {

}

// FUNCTION ///////////////////////////////////////////////////////////////
{% include "Connectors/Logger_Interface_function.cpp" with context %}

// GET/SET ////////////////////////////////////////////////////////////////
{% include "Connectors/Logger_Interface_get_set.cpp" with context %}

{{D_NAME}}& {{CLS_I_NAME}}::get_c() const {return *this->a_c;}
