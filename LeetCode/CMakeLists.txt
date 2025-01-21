cmake_minimum_required(VERSION 3.19)
project(LeetCode)

list(APPEND INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/DataStructure)

include(Q0099/Q0099.cmake)
include(Q0199/Q0199.cmake)
include(Q0299/Q0299.cmake)
include(Q0399/Q0399.cmake)
include(Q0699/Q0699.cmake)
include(Q0799/Q0799.cmake)
include(Q2099/Q2099.cmake)
#include(Q2199/Q2199.cmake)
include(Q2299/Q2299.cmake)
include(Q3099/Q3099.cmake)
#include(Q3199/Q3199.cmake)
include(Q3299/Q3299.cmake)
include(Tricks/Tricks.cmake)

add_executable(LeetCode ${SOURCES})

target_include_directories(LeetCode PRIVATE ${INCLUDE_DIRS})
target_link_options(LeetCode PRIVATE ${LIBS})