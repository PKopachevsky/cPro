cmake_minimum_required(VERSION 3.7)
project(socket)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES server.c)

add_executable(socket ${SOURCE_FILES})