cmake_minimum_required(VERSION 3.19)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure Code/CPP11_Random.cpp Code/LRU_Least_Recent_Used.cpp Code/Dynamic_Time_Warping.cpp Code/MyUtility.cpp Code/gcd_lcm.cpp Code/石子游戏.cpp Code/交错字符串.cpp Code/最长公共子串_自底向上.cpp)
add_executable(main main.cpp)