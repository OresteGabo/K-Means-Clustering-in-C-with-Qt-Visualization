# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/k_mean_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/k_mean_autogen.dir/ParseCache.txt"
  "k_mean_autogen"
  )
endif()
