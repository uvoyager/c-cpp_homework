cmake_minimum_required(VERSION 3.20)
project(CLionProjects C)

set(CMAKE_C_STANDARD 99)

add_executable( ex_3_1 cw_3/3_1.c)
add_executable( ex_3_2 cw_3/3_2.c)
add_executable (ex_3_3a cw_3/3_3a.c)
add_executable( ex_3_3b cw_3/3_3b.c)
add_executable( ex_3_4 cw_3/3_4.c)
add_executable (ex_3_5 cw_3/3_5.c)
add_executable( ex_3_6 cw_3/3_6.c)
add_executable( ex_3_7a cw_3/3_7a.c)
add_executable( ex_3_7b cw_3/3_7b.c)

add_executable( ex_3_20 hw_3/3_20.c)
add_executable( ex_3_23 hw_3/activation.c hw_3/main2.c)