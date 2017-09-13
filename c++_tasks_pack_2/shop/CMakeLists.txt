cmake_minimum_required(VERSION 2.5)
project(shop)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Stats.cpp
        Stats.h
        Category.cpp
        Category.h
        Item.cpp
        Item.h
        Order.cpp
        Order.h
        Customer.cpp
        Customer.h
        ShopException.h)
add_executable(shop ${SOURCE_FILES})