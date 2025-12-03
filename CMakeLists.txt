cmake_minimum_required(VERSION 3.23)
project(lab3 C)
set(CMAKE_GENERATOR MinGW Makefiles)
set(CMAKE_MAKE_PROGRAM C:/msys64/mingw64/bin/mingw32-make.exe)
set(CMAKE_C_COMPILER C:/msys64/mingw64/bin/gcc.exe)
set(CMAKE_BUILD_TYPE Debug)
add_executable(lab3
    src/main.c
    args/args.c
    src/io.c
    src/house.c
    src/generator.c
    src/algs/sort.c
    src/containers/deque.c
)
target_include_directories(lab3 PRIVATE
    src
    src/algs
    src/containers
    .
)