cmake_minimum_required(VERSION 3.5)

project(Sort)

set(CMAKE_CXX_STANDARD 23)

add_executable(sort sort.cc main.cc utils.cc)

target_compile_options(sort PRIVATE -O3 -Wall -Werror)