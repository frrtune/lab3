add_library(args STATIC ${CMAKE_CURRENT_SOURCE_DIR}/args.c)
target_include_directories(args PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})