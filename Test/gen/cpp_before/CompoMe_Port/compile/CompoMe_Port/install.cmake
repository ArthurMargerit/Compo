install(TARGETS ${compo_lib_name} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

# foreach(incf ${inc_file})
#   get_filename_component(incf_target ${incf} DIRECTORY)
#   install(FILES ${incf} DESTINATION ${incf_target})
# endforeach(incf)

install(DIRECTORY inc/ DESTINATION inc FILES_MATCHING PATTERN "*.hpp")
install(FILES CompoMe_Port.yaml DESTINATION .)
install(DIRECTORY compile/${compo_lib_name} DESTINATION compile)
include("${CMAKE_CURRENT_LIST_DIR}/Ext_install.cmake" OPTIONAL)