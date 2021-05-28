cmake_minimum_required(VERSION 3.19)
project(gnl_remake C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(gnl_remake
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        main.c)
