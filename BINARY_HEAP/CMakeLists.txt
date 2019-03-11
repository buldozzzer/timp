cmake_minimum_required(VERSION 3.13)
project(BINARY_HEAP)

set(CMAKE_CXX_STANDARD 14)

add_executable(BINARY_HEAP test.cpp BinaryHeap_main.cpp BinaryHeap.h BinaryHeap.cpp)