cmake_minimum_required(VERSION 3.17)
project(queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(queue main.cpp dynamic_queue.h static_queue.cpp static_queue.h)