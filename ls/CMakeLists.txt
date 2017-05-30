cmake_minimum_required(VERSION 3.7)
project(cp)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c fsize.c fsize.h)

add_executable(ls ${SOURCE_FILES})