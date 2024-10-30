# set fmt
include_directories(${CMAKE_SOURCE_DIR}/libs/fmt/11.0.2/include)
link_libraries(${CMAKE_SOURCE_DIR}/libs/fmt/11.0.2/lib/libfmt.lib)

# set google test
include_directories(${CMAKE_SOURCE_DIR}/libs/googletest/1.15.2/include)
list(APPEND LIBS -L${CMAKE_SOURCE_DIR}/libs/googletest/1.15.2/lib -lgtest_main -lgtest -lpthread)
