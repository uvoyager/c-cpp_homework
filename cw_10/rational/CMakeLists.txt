cmake_minimum_required(VERSION 3.20)
project(rational C)

set(CMAKE_C_STANDARD 99)

add_executable(rational
        rational.h
        rational.c
        main.c)