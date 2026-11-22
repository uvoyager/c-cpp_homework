set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 4.3)
add_executable(cw_18_1 18_1.cpp
        ../cw_15/ratio.cpp)
add_executable(cw_18_2 18_2.cpp)

target_include_directories(cw_18_1 PRIVATE ../cw_15)