cmake_minimum_required(VERSION 3.29)
project(weekly3 C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_C_STANDARD 11)

add_executable(weekly3 a13f3.c
        a26f3.c)
