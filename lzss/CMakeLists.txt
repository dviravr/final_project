cmake_minimum_required(VERSION 3.16)
project(lzss_try C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lzss_try
        deflate.c
        deflate.h
        inffast.c
        inffast.h
        inflate.c
        inflate.h
        adler32.c
        crc32.c
        crc32.h
        trees.c
        trees.h
        inftrees.c
        inftrees.h
        inffixed.h
        zconf.h
        zlib.h
        main.c
        zutil.c
        zutil.h
        )
