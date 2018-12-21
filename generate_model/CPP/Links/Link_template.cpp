#include "Links/{{NAME}}/{{NAME}}.hpp"


{{NAME}}::{{NAME}}()
{

}

{{NAME}}::~{{NAME}}()
{


}

{%if S.IN  == True %}
void {{NAME}}::set_to(Interface* pto)
{

}
{% endif %}
{%if S.OUT  == True %}
void {{NAME}}::set_from(Interface** pfrom)
{

}
{% endif %}
{%if S.DIRECT  == True %}
void {{NAME}}::set_from_to(Interface** pfrom, Interface* pto)
{

}
{% endif %}



void {{NAME}}::step()
{

}

void {{NAME}}::connect()
{

}

void {{NAME}}::disconnect()
{

}
