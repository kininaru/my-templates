cmake_minimum_required(VERSION 3.17)
project(my-templates)

set(CMAKE_CXX_STANDARD 14)

add_executable(my-templates main.cpp trees/min_heap.h trees/heap.h)