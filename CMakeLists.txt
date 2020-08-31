# cmake_minimum_required(VERSION <specify CMake version here>)
project(little-cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(little-cpp main.cpp)
add_executable(little-cpp src/basic_opeartions/basic-operations.cpp)