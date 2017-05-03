cmake_minimum_required(VERSION 3.7)
project(cPro)

set(CMAKE_C_STANDARD 11)

include_directories("lookup/")
include_directories("parser/")
add_subdirectory(lookup)
add_subdirectory(parser)