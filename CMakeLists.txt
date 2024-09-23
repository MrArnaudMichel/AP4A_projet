cmake_minimum_required(VERSION 3.29)
project(AP4A_projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AP4A_projet
        sources/main.cpp
        headers/main.h
        sources/server.cpp
        headers/server.h
        sources/sensor.cpp
        headers/sensor.h
        sources/scheduler.cpp
        headers/scheduler.h
        sources/data.cpp
        headers/data.h
)
