cmake_minimum_required(VERSION 3.7)
project(lookup)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c hash.h hash.c lookup.h lookup.c ../parser/main.c ../parser/tree.h)

add_executable(lookup ${SOURCE_FILES})