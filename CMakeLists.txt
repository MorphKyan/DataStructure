cmake_minimum_required(VERSION 3.19)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure CPP11_Random.cpp LRU_Least_Recent_Used.cpp Dynamic_Time_Warping.cpp MyUtility.cpp gcd.cpp)
add_executable(main main.cpp)