cmake_minimum_required(VERSION 2.5)
project(myMalloc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 ")

set(SOURCE_FILES
        myMalloc.c
        myMalloc.h
        test.c)

add_executable(myMalloc ${SOURCE_FILES})
target_link_libraries(myMalloc pthread)