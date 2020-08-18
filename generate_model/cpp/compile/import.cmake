set(_include_directories "")

set(_include_directories ${_include_directories} "./inc")
include("./compile/{{FILE.replace('.yaml','')}}_import.cmake")

{% for i_v in IMPORTS.values() -%}
{% with MY_PATH=i_v.PATH.replace("/"+i_v.NAME ,""), MY_FILE=i_v.NAME, IMPORTS=i_v.MAIN.IMPORTS -%}
{% include "compile/import.rec" with context %}
{% endwith -%}
{%- endfor -%}
