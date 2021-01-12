# cmake_minimum_required(VERSION <specify CMake version here>)
project(little-cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(little-cpp learn-cpp/basic-operation/define/Circle.h learn-cpp/basic-operation/define/Circle.cpp learn-cpp/basic-operation/define/main.cpp learn-cpp/basic-operation/archive/say.cpp learn-cpp/basic-operation/archive/say.h learn-cpp/basic-operation/archive/sayHello.cpp learn-cpp/basic-operation/archive/saymain.cpp)
#add_executable(little-cpp learn-cpp/basic-operation/basic-operations.cpp)