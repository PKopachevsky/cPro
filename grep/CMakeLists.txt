cmake_minimum_required(VERSION 3.7)
project(grep)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES grep.c)

add_executable(grep ${SOURCE_FILES})