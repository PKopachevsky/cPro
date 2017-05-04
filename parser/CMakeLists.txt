cmake_minimum_required(VERSION 3.7)
project(parse)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c utils.h utils.c parser.h parser.c tree.c)

add_executable(main ${SOURCE_FILES})