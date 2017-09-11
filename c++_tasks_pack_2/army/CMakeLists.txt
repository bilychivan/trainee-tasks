cmake_minimum_required(VERSION 3.5)
project(army)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Units/archer.cpp
        Units/archer.h
        Units/mage.cpp
        Units/mage.h
        Units/priest.cpp
        Units/priest.h
        Units/skeleton.cpp
        Units/skeleton.h
        Units/vampire.cpp
        Units/vampire.h
        Units/warlock.cpp
        Units/warlock.h
        Units/warrior.cpp
        Units/warrior.h
        army.cpp
        army.h
        Units/unit.h
        Units/unit.cpp
        Units/armyException.h
        Units/magicUnit.cpp
        Units/magicUnit.h
        Spells/spell.h
        Spells/heal.cpp
        Spells/heal.h
        Spells/summonSkeleton.h
        Spells/summonSkeleton.cpp
        Spells/summonSkeleton.h
        Spells/fireball.cpp
        Spells/fireball.h)

add_executable(army ${SOURCE_FILES})
include_directories(Spells Units)