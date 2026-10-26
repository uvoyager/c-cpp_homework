cmake_minimum_required(VERSION 3.20)
project(rectangle C)

set(CMAKE_C_STANDARD 99)

add_executable(rectangle
        rectangle.h
        rectangle.c
        main.c)