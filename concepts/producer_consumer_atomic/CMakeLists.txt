cmake_minimum_required(VERSION 3.17)
project(producer_consumer_atomic)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
add_executable(producer_consumer_atomic main.cpp)