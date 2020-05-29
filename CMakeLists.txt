cmake_minimum_required(VERSION 3.16)
project(2d_closest_pair)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(2d_closest_pair
    source/include/2d_problem.h
    source/include/merge_sort.h
    source/include/point.h
    source/src/2d_problem.cpp
    source/src/main.cpp
    source/src/merge_sort.cpp)
