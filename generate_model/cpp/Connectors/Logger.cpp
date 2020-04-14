{% set i = MAIN.INTERFACES[INTERFACE] %}
#include <sstream>

#include "connectors/{{D_NAME.replace('::','/')}}.hpp"
#include "Interfaces/{{i.D_NAME.replace('::','/')}}/{{i.NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}
{% include "Connectors/Logger_Interface.cpp" with context %}
{% include "helper/namespace_close.hpp" with context %}
