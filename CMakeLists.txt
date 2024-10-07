cmake_minimum_required(VERSION 3.29)
project(AP4A_projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AP4A_projet
        main.cpp
        main.h
        server.cpp
        server.h
        sensortemp.cpp
        sensortemp.h
        scheduler.cpp
        scheduler.h
        data.cpp
        data.h

        # Sensors
        slight.h
        slight.cpp
        Sensor.cpp
        Sensor.h
)
