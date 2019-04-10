{%- if def is none or def.__str__() == "" or def == '' %}
    {%- if "DEFAULT" in TYPE and not Function.model_test.is_struct(TYPE.NAME, STRUCTS)%}
      {%- with TYPE=TYPE, def=TYPE.DEFAULT-%}
          {%- include "helper/lap.cpp" with context -%}
      {%- endwith %}
    {%- else %}
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/
    {%-  endif %}
{%-else%}
    {%- if Function.model_test.is_struct(TYPE.NAME, STRUCTS) -%}
{{TYPE.NAME}}(
        {%- for c in TYPE.DATA-%}
            {%- with TYPE=c.TYPE, def=def[c.NAME]-%}
                {%- include "helper/lap.cpp" with context -%}
             {%- endwith -%}
             {%-if not loop.last-%},{%-endif-%}
         {%- endfor -%})
     {%-else-%}
         {{def}}
     {%- endif -%}
{%- endif %}
