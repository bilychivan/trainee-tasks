cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Shop)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(Include)

file(GLOB SOURCE_FILES "Source/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})