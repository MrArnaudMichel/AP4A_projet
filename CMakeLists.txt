cmake_minimum_required(VERSION 3.29)
project(AP4A_projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AP4A_projet
        main.cpp
        main.h
        server.cpp
        server.h
)
