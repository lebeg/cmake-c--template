cmake_minimum_required(VERSION 3.14)
project(myproject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(BUILD_TESTS "Build the tests" ON)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

option(CHECK_CLANG_TIDY "Check with clang-tidy" ON)
option(FIX_CLANG_TIDY "Perform fixes for clang-tidy" OFF)

if(CHECK_CLANG_TIDY)
  find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable"
  )

  if(CLANG_TIDY_EXE)
    set(CLANG_TIDY_EXE "${CLANG_TIDY_EXE}" "-checks=*,-clang-analyzer-alpha.*")
    if(FIX_CLANG_TIDY)
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}" "-fix")
    else()
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
  else()
    message(STATUS "clang-tidy not available.")
  endif()
endif()

add_executable(myproject main.cpp)
