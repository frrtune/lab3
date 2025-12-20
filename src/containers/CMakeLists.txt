add_library(deque STATIC ${CMAKE_CURRENT_SOURCE_DIR}/deque.c)
target_include_directories(deque PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})