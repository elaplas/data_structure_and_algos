cmake_minimum_required(VERSION 3.17)
project(measure_calls)

set(CMAKE_CXX_STANDARD 17)

add_executable(measure_calls main.cpp CallFrequency.h CallFrequency.cpp)