# cmake_minimum_required(VERSION <specify CMake version here>)
project(little-cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(little-cpp "main.cpp" "learn-cpp/primer/chapter02/ptr.cpp" "learn-cpp/primer/chapter02/basic.cpp" "learn-cpp/primer/chapter02/structs.cpp")