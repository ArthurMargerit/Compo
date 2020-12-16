set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/{{FILE.replace('.yaml','')}}/Ext_import.cmake" OPTIONAL)
{% set already_imported = [FILE] %}
{% for i_v in IMPORTS.values() -%}
{% if i_v.NAME not in already_imported %}
{% set _ = already_imported.append(i_v.NAME) %}
{% with MY_PATH=i_v.PATH.replace("/"+i_v.NAME ,""), MY_FILE=i_v.NAME, IMPORTS=i_v.MAIN.IMPORTS -%}
{% include "compile/import.rec" with context %}
{% endwith -%}
{% endif %}
{%- endfor -%}
