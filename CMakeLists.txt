cmake_minimum_required(VERSION 3.15)
project(food_ordering)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(food_ordering
        .idea/workspace.xml
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/food_ordering.cbp
        cmake-build-debug/food_ordering.exe
        cmake-build-debug/Makefile
        choices.c
        choices.h
        CMakeLists.txt
        constants.h
        display_order.c
        display_order.h
        main.c
        user.c
        user.h)
