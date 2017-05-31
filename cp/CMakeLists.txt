cmake_minimum_required(VERSION 3.7)
project(cp)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c ../files/fopen.c ../grep/grep.c ../files/fopen.c)

add_executable(cp ${SOURCE_FILES})