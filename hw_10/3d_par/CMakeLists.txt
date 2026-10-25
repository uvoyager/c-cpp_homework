cmake_minimum_required(VERSION 3.20)
project(3d_par C)

set(CMAKE_C_STANDARD 99)

add_executable(3d_par
        par.h
        par.c
        main.c)