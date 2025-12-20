add_library(io STATIC ${CMAKE_CURRENT_SOURCE_DIR}/io.c)
target_link_libraries(io deque)
target_include_directories(io PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})