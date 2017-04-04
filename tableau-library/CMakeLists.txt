cmake_minimum_required(VERSION 3.6)
project(tableau_library)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        tableau.c
        tableau.h)

add_executable(tableau_library ${SOURCE_FILES})