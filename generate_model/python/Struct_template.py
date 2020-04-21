#!/usr/bin/env python

{%if PARENT%}
from  src.struct.{{PARENT.NAME}} import {{PARENT.NAME}}
{%else%}
from src.struct.Struct import Struct
{%endif%}

{% set include_key = [] %}
{% for d in DATA %}
{%- if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
{%- if d.TYPE.NAME not in include_key -%}
from src.struct.{{d.TYPE.NAME}} import {{d.TYPE.NAME}}
{% set _ = include_key.append(d.TYPE.NAME) -%}
{%- endif %}
{%- endif %}
{% endfor %}



class {{NAME}}({%if PARENT%}{{PARENT.NAME}}{%else%}Struct{%endif%}):

    def __init__(self,
                 {%for d in DATA-%}
                 p_{{d.NAME}} = {%if "WITH" in d%}{{d.WITH}}{%elif "DEFAULT" in d.TYPE %}{{d.TYPE.DEFAULT}}{%else%}{{d.TYPE.NAME}}(){%endif-%}
                 {%-if not loop.last%},{%endif-%}
                 {% endfor -%}
    ):

        "docstring"
        {%if PARENT%}
        super({{NAME}},self).__init__()
        {%endif%}
        {%for d in DATA-%}
        self.{{d.NAME}} = p_{{d.NAME}}
        {% endfor %}

    {%for f in FUNCTION-%}
    def {{f.NAME}}(
            {%-for p in f.SIGNATURE-%}
            {{p.NAME}}
            {%-if not loop.last%},{%endif-%}
            {%-endfor-%}
    ):
        {%if f.RETURN.NAME == "void"%}pass{%else%}return {{f.RETURN.NAME}}(){%endif%}

    {% endfor %}

    def __str__(self):
        strs = "{"
        {%if PARENT %}
        strs+="PARENT:"+{{PARENT.NAME}}.__str__(self)
        {%if DATA.__len__()!=0%}
        strs+=","
        {%endif%}
        {%endif%}

        {%for d in DATA-%}
        strs+= "{{d.NAME}}"
        strs+= ":"
        strs+= str(self.{{d.NAME}})
        {%-if not loop.last%}

        strs+= ","

        {%endif-%}
        {% endfor %}
        strs+= "}"

        return strs
