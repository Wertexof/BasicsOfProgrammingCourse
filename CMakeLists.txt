cmake_minimum_required(VERSION 3.20)
project(vectors_project C)

set(CMAKE_C_STANDARD 11)

add_executable(vectors_project main.c)

add_library(test libs/tasks.c libs/tests.c libs/tasks.c libs/data_structures/string/string_.c libs/data_structures/string/string_.h)
target_link_libraries(vectors_project test)
target_link_libraries(vectors_project data_structures)