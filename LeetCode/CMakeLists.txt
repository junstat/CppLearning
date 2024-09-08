cmake_minimum_required(VERSION 3.19)
project(LeetCode)

include(${CMAKE_SOURCE_DIR}/depends.cmake)

include(Q0099/Q0099.cmake)
include(Q0999/Q0999.cmake)
include(Q3199/Q3199.cmake)

message("in LeetCode\\CMakeLists.txt")
message(${CMAKE_CURRENT_LIST_DIR})
message(${CMAKE_SOURCE_DIR})

add_executable(LeetCode ${SOURCES})