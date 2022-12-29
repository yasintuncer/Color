cmake_minimum_required(VERSION 3.16)
project(color)

set(CMAKE_CXX_STANDARD 11)
include_directories(src)
add_library(color STATIC src/Color.cpp src/Transformation.cpp)


add_executable(color_test test/color_test.cpp)
target_link_libraries(color_test color)
