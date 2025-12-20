add_library(house STATIC ${CMAKE_CURRENT_SOURCE_DIR}/house.c)
target_include_directories(house PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})