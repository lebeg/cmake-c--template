cmake_minimum_required(VERSION 3.14)
project(ubisoft)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build the tests" ON)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

add_executable(ubisoft main.cpp)
