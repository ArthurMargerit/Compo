set(_links_lib "")
include("./compile/{{FILE.replace('.yaml','')}}_links.cmake")

{% for i_k,i_v in IMPORTS.items() -%}
{% with MY_PATH=i_v.PATH.replace("/"+i_v.NAME ,""), MY_FILE=i_v.NAME, IMPORTS=i_v.MAIN.IMPORTS -%}
{% include "compile/links.rec" with context %}
{% endwith -%}
{%- endfor -%}
