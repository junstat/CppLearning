cmake_minimum_required(VERSION 3.19)
project(LeetCode)

list(APPEND INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/DataStructure)

include(${CMAKE_SOURCE_DIR}/depends.cmake)

include(Q0099/Q0099.cmake)
#include(Q0199/Q0199.cmake)
#include(Q0999/Q0999.cmake)
#include(Q3199/Q3199.cmake)
#include(Q2199/Q2199.cmake)

add_executable(LeetCode ${SOURCES})

target_include_directories(LeetCode PRIVATE ${INCLUDE_DIRS})
target_link_options(LeetCode PRIVATE ${LIBS})