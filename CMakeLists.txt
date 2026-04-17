cmake_minimum_required(VERSION 3.27)
project(YeSiYoPrototip C)

set(CMAKE_C_STANDARD 11)

add_executable(YeSiYoPrototip
        kullanici.c
        yemek.c
        yemek.h
        siparis.h
        siparis.c)
