cmake_minimum_required(VERSION 3.23)
project(lab3 C)
set(CMAKE_GENERATOR MinGW Makefiles)
set(CMAKE_MAKE_PROGRAM mingw32-make.exe)
set(CMAKE_C_COMPILER cc.exe)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/containers)

add_executable(lab3
    src/main.c
    #args/args.c
    #src/io.c
    #src/house.c
    #src/generator.c
    #src/algs/sort.c
    #src/containers/deque.c
)
target_link_libraries(lab3
    deque
    house
    io
    args
    algs)

target_include_directories(lab3 PRIVATE
    src
    #src/algs
    # src/containers
    .
)