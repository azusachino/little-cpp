cmake_minimum_required(VERSION 3.20.0)

project(little-cpp 
      LANGUAGES C CXX
      VERSION 0.0.1
      DESCRIPTION "learning progress of c++")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

add_subdirectory(practices)

cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)

add_executable(little-cpp "main.cpp")