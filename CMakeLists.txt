cmake_minimum_required(VERSION 3.20)
project(Lab9_SingleProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(library_app
        library/Library.cpp
        library/main_library.cpp
)

add_executable(gilded_rose_app
        gilded_rose/GildedRose.cpp
        gilded_rose/main_gilded_rose.cpp
)