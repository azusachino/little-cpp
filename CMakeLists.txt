
cmake_minimum_required(VERSION 3.16.0)

# setup hunter gate
include("cmake/hunter-gate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.18.16.tar.gz"
        SHA1 "6cbca2b0e7605ad8ea22ee3527850996436f71b8"
)

project(little-cpp 
      LANGUAGES C CXX
      VERSION 0.0.1
      DESCRIPTION "cpp learning project")

# set means define a variable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_FILES "hello.c")

# set for cmake module
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Loads and runs CMake code from the file given. Variable reads and writes access the scope of the caller (dynamic scoping). 
include(config)
include(build)

# Copy a file to another location and modify its contents
CONFIGURE_FILE(${CMAKE_MODULE_PATH}/build.h.in ${CMAKE_BINARY_DIR}/build.h)
CONFIGURE_FILE(${CMAKE_MODULE_PATH}/config.h.in ${CMAKE_BINARY_DIR}/config.h)

add_subdirectory(curl_test)
add_subdirectory(src)
add_subdirectory(practices)

# generate installation rules for a project
INSTALL(FILES README.md DESTINATION ${PROJECT_SOURCE_DIR})
INSTALL(PROGRAMS hello.sh DESTINATION bin)
INSTALL(DIRECTORY doc/ DESTINATION ${PROJECT_SOURCE_DIR})

# 动态生成库文件
add_library(my_math SHARED src/my_math.cc)
target_include_directories(my_math PRIVATE ${PROJECT_SOURCE_DIR}/include)
set_target_properties(my_math PROPERTIES PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/include/my_math.h)

# 生成可执行文件
add_executable(my_math_app src/my_math_app.cc)
target_link_libraries(my_math_app my_math)
target_include_directories(my_math_app PRIVATE ${PROJECT_SOURCE_DIR}/include)

INSTALL(TARGETS my_math my_math_app
        EXPORT MyLibTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include
)

# 写入库的版本信息
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    MyMathConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion  # 表示该函数库向下兼容
)

# print message while build with cmake
message(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})

# build target
add_executable(little-cpp "main.cpp")
add_executable(hello ${SOURCE_FILES})
