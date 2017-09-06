cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(Army)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(Include)

set(SOURCE_FILES
    Source/archer.cpp
    Source/caster.cpp
    Source/entity.cpp
    Source/helpers.cpp
    Source/healer.cpp
    Source/mage.cpp
    Source/main.cpp
    Source/skeleton.cpp
    Source/test.cpp
    Source/teamfight.cpp
    Source/vampire.cpp
    Source/warlock.cpp
    Source/warrior.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})