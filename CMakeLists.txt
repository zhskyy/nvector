cmake_minimum_required (VERSION 2.6)
project(nykytich)

# The version number.
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

set (CMAKE_CXX_STANDARD 11)
find_package (Threads)



# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("../gtest/include/")

add_executable(${PROJECT_NAME} "src/main.cpp" "tests/nvector_tests.cpp")
target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/bin/libgtest.a" ${CMAKE_THREAD_LIBS_INIT})

