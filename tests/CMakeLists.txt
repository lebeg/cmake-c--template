include(FetchContent)

fetchcontent_declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.8.0
)

fetchcontent_getproperties(googletest)
if(NOT googletest_POPULATED)
  fetchcontent_populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

macro(package_add_test TESTNAME)
  add_executable(${TESTNAME} ${ARGN})
  target_link_libraries(${TESTNAME} PRIVATE gtest gmock gtest_main myproject_library)
  target_compile_features(${TESTNAME} PRIVATE cxx_std_17)
  target_include_directories(${TESTNAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
  add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
  set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(tests test.cpp)
