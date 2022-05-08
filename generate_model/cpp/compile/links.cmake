set(_links_lib "")
{% set main_build=Function.os.environ["COMPOME_BUILD"]%}
{% set main_source=Function.os.path.realpath(".")%}

include("${CMAKE_CURRENT_LIST_DIR}/Ext_links.cmake" OPTIONAL)
{% set already_imported = [FILE] %}
{% for i_v in IMPORTS.values() -%}
{% if i_v.NAME not in already_imported %}
{% set _ = already_imported.append(i_v.NAME) %}
{% with MY_PATH=i_v.PATH.replace("/"+i_v.NAME ,""), MY_FILE=i_v.NAME, IMPORTS=i_v.MAIN.IMPORTS -%}
{% include "compile/links.rec" with context %}
{% endwith -%}
{% endif %}
{%- endfor -%}
