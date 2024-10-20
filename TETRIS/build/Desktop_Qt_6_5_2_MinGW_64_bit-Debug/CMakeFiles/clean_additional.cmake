# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "src\\CMakeFiles\\TetrisProject_autogen.dir\\AutogenUsed.txt"
  "src\\CMakeFiles\\TetrisProject_autogen.dir\\ParseCache.txt"
  "src\\TetrisProject_autogen"
  )
endif()
