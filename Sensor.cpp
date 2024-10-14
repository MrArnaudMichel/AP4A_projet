//
// Created by arnaud on 14/10/24.
//

#include "Sensor.h"

Sensor::Sensor() {
    id++;
    duration = 0;
    timeRemaining = duration;
    server = nullptr;
}

Sensor::Sensor(const Sensor &sensor) {
    id = sensor.id + 1;
    duration = sensor.duration;
    timeRemaining = sensor.timeRemaining;
    server = sensor.server;
}

Sensor & Sensor::operator=(const Sensor &sensor) {
    if (this != &sensor) {
        id = sensor.id + 1;
    }
    duration = sensor.duration;
    timeRemaining = sensor.timeRemaining;
    server = sensor.server;

    return *this;
}