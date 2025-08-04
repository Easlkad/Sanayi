# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\appSanayi_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appSanayi_autogen.dir\\ParseCache.txt"
  "appSanayi_autogen"
  )
endif()
