cmake_minimum_required(VERSION 3.29)
project(AP4A_projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AP4A_projet
        main.cpp
        main.h
        Sensors/Sensor.cpp
        Sensors/Sensor.h
        Server.cpp
        Server.h
        Scheduler.cpp
        Scheduler.h
        Data.h
        Sensors/SensorBool.cpp
        Sensors/SensorBool.h
        Sensors/SensorFloat.cpp
        Sensors/SensorFloat.h
        Sensors/SensorInteger.cpp
        Sensors/SensorInteger.h
)
