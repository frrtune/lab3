cmake_minimum_required(VERSION 3.23)
project(lab3 C)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src/containers)
add_subdirectory(src/algs)
add_subdirectory(src/house)
add_subdirectory(src/io)
add_subdirectory(args)

add_executable(lab3
    src/main.c
)

target_link_libraries(lab3
    deque
    house
    io  
    args
    sort
)

target_include_directories(lab3 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_executable(benchmark
    src/benchmark.c
)

target_link_libraries(benchmark
    deque
    house
    sort
)

target_include_directories(benchmark PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)