cmake_minimum_required(VERSION 3.20)
project(date C)

set(CMAKE_C_STANDARD 99)

add_executable(date
        date.h
        date.c
        main.c)