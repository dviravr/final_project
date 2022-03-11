cmake_minimum_required(VERSION 3.16)
project(lzss_project C)

set(CMAKE_C_STANDARD 99)

add_executable(lzss_project main.c lzss.h lzss.c lzlocal.h list.c bitfile.c bitfile.h)
