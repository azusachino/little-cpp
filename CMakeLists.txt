project(little-cpp)

cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

aux_source_directory(src src)

add_executable(little-cpp "main.cc")