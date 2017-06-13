cmake_minimum_required(VERSION 2.6)
project(unittest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -DALLOC_TEST")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(gtest gtest/gtest-all.cc gtest/gtest_main.cc)
target_link_libraries(gtest pthread)

set(SRC_FILES
	1_test.cpp
	2_3a.cpp
	3_test_fixture.cpp
	4_google_test.cpp 
	5_suite_fixture.cpp 
	6_global_fixture.cpp 
	7_memory.cpp 
	7_timeout.cpp
)
add_executable(unittest ${SRC_FILES})
target_link_libraries(unittest gtest)
