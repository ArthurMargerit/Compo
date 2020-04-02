
{% set CLS_I_NAME = NAME+"_"+ic.NAME %}

// Constructor
{{CLS_I_NAME}}::{{CLS_I_NAME}}({{D_NAME}}* p_c): {{ic.NAME}}(), _c(p_c){}

{{CLS_I_NAME}}::~{{CLS_I_NAME}}(){}

{{D_NAME}}& {{CLS_I_NAME}}::get_c() {
  return *_c;
}

  // Function ///////////////////////////////////////////////////////
{%include "Connectors/Async_Interface_function.cpp" with context %}


