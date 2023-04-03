cmake_minimum_required(VERSION 3.18)

project(Challenge VERSION 0.1)

add_executable(challenge configurations.h image_processing_parameters.h motor_parameters.h preset.h meta_data.h
        main.cpp parameters.h)

target_include_directories(challenge PRIVATE vendor/)
target_compile_features(challenge PRIVATE cxx_std_17)

