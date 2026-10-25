cmake_minimum_required(VERSION 3.20)
project(exams C)

set(CMAKE_C_STANDARD 99)

add_executable(exams
        exams_res.h
        exams_res.c
        main.c)