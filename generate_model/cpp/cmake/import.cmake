{%for l_import in IMPORTS %}
{% set l_import_name = l_import.replace(".yaml","") %}
find_package({{l_import_name}} REQUIRED)
target_link_libraries({{options.project.name}} PUBLIC {{l_import_name}})
{%endfor%}
