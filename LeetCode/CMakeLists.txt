cmake_minimum_required(VERSION 3.19)
project(LeetCode)

list(APPEND INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/DataStructure)

include(${CMAKE_SOURCE_DIR}/depends.cmake)

include(Q0099/Q0099.cmake)
include(Q0199/Q0199.cmake)
include(Q0699/Q0699.cmake)
include(Q0799/Q0799.cmake)
include(Q2099/Q2099.cmake)
#include(Q2199/Q2199.cmake)
include(Q2299/Q2299.cmake)
include(Q3099/Q3099.cmake)
#include(Q3199/Q3199.cmake)
include(Q3299/Q3299.cmake)

add_executable(LeetCode ${SOURCES}
        Tricks/EnumTest.cpp
        Tricks/FileTest.cpp)

target_include_directories(LeetCode PRIVATE ${INCLUDE_DIRS})
target_link_options(LeetCode PRIVATE ${LIBS})