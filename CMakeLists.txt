cmake_minimum_required(VERSION 3.19)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure CPP11_Random.cpp LRU_Least_Recent_Used.cpp DynamicTimeWarping.cpp)
add_executable(edit edit.cpp)
add_executable(main main.cpp)