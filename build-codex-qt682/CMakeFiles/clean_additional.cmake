# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\appPatient_Manager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appPatient_Manager_autogen.dir\\ParseCache.txt"
  "appPatient_Manager_autogen"
  )
endif()
