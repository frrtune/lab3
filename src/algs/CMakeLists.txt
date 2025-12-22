add_library(sort STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sort.c ${CMAKE_CURRENT_SOURCE_DIR}/quick_sort.c)
target_link_libraries(sort deque)
target_include_directories(sort PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})