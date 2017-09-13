cmake_minimum_required(VERSION 2.8)

project(memory_manager_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -fsanitize=address -fno-omit-frame-pointer")

include_directories(memory_manager_library/Include)

macro(build_lirbary LIBRARY_NAME)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR})

    add_library(${LIBRARY_NAME}_SHARED SHARED Source/${LIBRARY_NAME}.cpp)
    add_library(${LIBRARY_NAME}_STATIC STATIC Source/${LIBRARY_NAME}.cpp)

    target_include_directories(${LIBRARY_NAME}_SHARED PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_include_directories(${LIBRARY_NAME}_STATIC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endmacro()

add_subdirectory(${CMAKE_SOURCE_DIR}/memory_manager_library)
add_subdirectory(${CMAKE_SOURCE_DIR}/testing)