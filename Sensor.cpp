//
// Created by arnaud on 14/10/24.
//

#include "Sensor.h"

int Sensor::CONST_ID = 0;

Sensor & Sensor::operator=(const Sensor &sensor) {
    if (this == &sensor) {
        return *this;
    }
    duration = sensor.duration;
    timeRemaining = sensor.timeRemaining;
    server = sensor.server;

    return *this;
}

void Sensor::update() {
    if (timeRemaining > 0) {
        timeRemaining--;
        return;
    }
    execute();
    timeRemaining = duration;
}