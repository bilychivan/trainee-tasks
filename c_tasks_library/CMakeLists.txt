cmake_minimum_required(VERSION 2.8)

project(c_tasks_library_project)

include_directories(simple_c_library/Include simple_c_library_2/Include)

macro(build_lirbary LIBRARY_NAME)
    include_directories(Include)

    add_library(${LIBRARY_NAME}_SHARED SHARED Source/${LIBRARY_NAME}.c)
    add_library(${LIBRARY_NAME}_STATIC STATIC Source/${LIBRARY_NAME}.c)

    target_include_directories(${LIBRARY_NAME}_SHARED PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_include_directories(${LIBRARY_NAME}_STATIC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
endmacro()

add_subdirectory(${CMAKE_SOURCE_DIR}/simple_c_library)
add_subdirectory(${CMAKE_SOURCE_DIR}/simple_c_library_2)
add_subdirectory(${CMAKE_SOURCE_DIR}/testing)