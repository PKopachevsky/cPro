cmake_minimum_required(VERSION 3.7)
project(cPro)

set(CMAKE_C_STANDARD 11)

include_directories("lookup/")
include_directories("parser/")
include_directories("cp/")
include_directories("ls/")
include_directories("grep/")
add_subdirectory(lookup)
add_subdirectory(parser)
add_subdirectory(cp)
add_subdirectory(ls)
add_subdirectory(grep)
