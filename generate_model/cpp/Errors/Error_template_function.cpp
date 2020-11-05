#include "Errors/{{F_NAME}}.hpp"

{%include "helper/namespace_open.hpp" with context%}

{%- with NAME=NAME, FUNCTION=FUNCTION, PARENT=PARENT, FIRST_PARENT=PARENT -%}
{%- include "Structs/Struct_function.cpp" with context -%}
{%- endwith -%}

{%include "helper/namespace_close.hpp" with context%}
