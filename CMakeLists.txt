cmake_minimum_required(VERSION 3.19)
project(CppLearning)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_SOURCE_DIR}/depends.cmake)
include(ADTs/ADTs.cmake)
add_subdirectory(LeetCode)


add_executable(CppLearning ${SOURCES})
