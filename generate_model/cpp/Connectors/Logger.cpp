{% set i = MAIN.INTERFACES[INTERFACE] %}
#include <sstream>

#include "connectors/{{F_NAME}}.hpp"
#include "Interfaces/{{i.F_NAME}}/{{i.NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}
{% include "Connectors/Logger_Interface.cpp" with context %}
{% include "helper/namespace_close.hpp" with context %}
