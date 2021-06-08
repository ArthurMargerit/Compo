#pragma once

{%if PARENT -%}
#include "Ports/{{PARENT.F_NAME}}.hpp"
{%else%}
#include "Ports/Port.hpp"
{%-endif%}

{%set MIX = (DATA if DATA else []) + (KEY if KEY else []) %}

// TYPES
{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, MIX).values() %}
// d.D_NAME
{% if d.NATIF != True %}
#include "Types/{{d.F_NAME}}.hpp"
{% if d.POINTER == True %}
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}.hpp"
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}_fac.hpp"
{%endif%} {%endif%} {%endfor%}
// STRUCT
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, MIX).values() %}
#include "Structs/{{d.F_NAME}}.hpp"
{% endfor %}

{% include "helper/namespace_open.hpp" with context %}
class {{NAME}} :public {%if PARENT %}{{PARENT.D_NAME}}{%else%}CompoMe::Port{%endif%}
{
 public:
  //! Default constructor
  {{NAME}}();

  //! Destructor
  virtual ~{{NAME}}() noexcept;


  {%if "FUNCTION_IN" in KIND %}
  // FUNCTION_IN //////////////////////////////////////////////////////////////
  virtual bool connect_interface({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}, {%endfor%}CompoMe::Interface& p_i);

  virtual CompoMe::Interface& get_interface({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}} {%if not loop.last%},{%endif%}{%endfor%});
  {%if KEY %}
  std::map<std::tuple<{%for k in KEY %}{{k.TYPE.D_NAME}}{%if not loop.last%},{%endif%}{%endfor%}>,CompoMe::Interface*> get_interfaces_list();
  {%endif%}


  virtual bool is_connected_interface(CompoMe::Interface& p_i);
  virtual bool is_connected_interface({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%});

  virtual bool disconnect_interface({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%});
  virtual bool disconnect_interface(CompoMe::Interface& p_i);
  {% endif %}


  {%if "FUNCTION_OUT" in KIND %}
  // FUNCTION OUT//////////////////////////////////////////////////////////////
  virtual bool connect_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}, {%endfor%}CompoMe::Require_helper& p_r);

  virtual CompoMe::Require_helper& get_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}} {%if not loop.last%},{%endif%}{%endfor%});
  {%if KEY %}
  std::map<std::tuple<{%for k in KEY %}{{k.TYPE.D_NAME}}{%if not loop.last%},{%endif%}{%endfor%}>,CompoMe::Require_helper*> get_require_list();
  {%endif%}

  virtual bool is_connected_require(CompoMe::Require_helper& p_i);
  virtual bool is_connected_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%});

  virtual bool disconnect_require({%for k in (KEY if KEY else []) %}{{k.TYPE.D_NAME}} {{k.NAME}}{%if not loop.last%},{%endif%}{%endfor%});
  virtual bool disconnect_require(CompoMe::Require_helper& p_r);
  {% endif %}

  // FUNCTION /////////////////////////////////////////////////////////////////
  {%- for f in FUNCTION %}
  virtual {{ f.RETURN.D_NAME }} {{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    );
  {%- endfor %}

  // GET/SET //////////////////////////////////////////////////////////////////
  {%- for v in DATA %}
  {{v.TYPE.D_NAME}} get_{{v.NAME}}() const;
  void set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}});
  {%- endfor %}

 private:
  {%- for v in DATA %}
  {{v.TYPE.D_NAME}} {{v.NAME}};
  {%- endfor %}

  // YOU PRIVATE DATA//////////////////////////////////////////////////////////

  //---------------------------------------------------------------------------
};

{% include "helper/namespace_close.hpp" with context %}
