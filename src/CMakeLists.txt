file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/../include/*.h")

set(THE_LIB_NAME ${THE_PROJECT_NAME}_library)

add_library(${THE_LIB_NAME} lib.cpp ${HEADER_LIST})
target_compile_features(${THE_LIB_NAME} PRIVATE cxx_std_17)
target_include_directories(${THE_LIB_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
