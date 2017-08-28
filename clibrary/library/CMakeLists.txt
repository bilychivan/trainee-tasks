cmake_minimum_required(VERSION 2.8.9)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_library(lyslib_shared SHARED ${SOURCES})
add_library(lyslib_static STATIC ${SOURCES})

target_include_directories (lyslib_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories (lyslib_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

