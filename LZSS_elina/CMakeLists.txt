cmake_minimum_required(VERSION 3.16)
project(LZSS_elina)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LZSS_elina
        Compress.cpp
        Compress.h
        Decompress.cpp
        Decompress.h
        main.cpp
        main.h
        Stat.cpp
        Stat.h)
