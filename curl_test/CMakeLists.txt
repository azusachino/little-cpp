cmake_minimum_required(VERSION 3.16.0)

hunter_add_package(curl)

find_package(curl CONFIG REQUIRED)

add_executable(curl_test main.c)
target_link_libraries(curl_test PUBLIC curl)

if (CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIR})
  target_link_libraries(curl_test ${CURL_LIBRARY})
else(CURL_FOUND)
  message(FATAL_ERROR "CURL Library not found")
endif(CURL_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)