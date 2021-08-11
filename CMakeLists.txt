cmake_minimum_required(VERSION 3.19)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure Code/CPP11_Random.cpp Code/LRU_Least_Recent_Used.cpp Code/Dynamic_Time_Warping.cpp Code/MyUtility.cpp Code/gcd.cpp Code/石子游戏.cpp)
add_executable(main main.cpp)