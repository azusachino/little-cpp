cmake_minimum_required(VERSION 3.16.0)

add_executable(curl_test main.c)

find_package(curl)

if (CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIR})
  target_link_libraries(curl_test ${CURL_LIBRARY})
else(CURL_FOUND)
  message(FATAL_ERROR "CURL Library not found")
endif(CURL_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)