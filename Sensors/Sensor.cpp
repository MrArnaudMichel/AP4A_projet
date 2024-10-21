//
// Created by arnaud on 14/10/24.
//

#include "Sensor.h"
// Static variable initialization
int Sensor::CONST_ID = 0;

/**
 * Copy constructor for Sensor
 * @param sensor to copy
 * @return the copied sensor
 */
Sensor & Sensor::operator=(const Sensor &sensor) {
    if (this == &sensor) {
        return *this;
    }
    duration = sensor.duration;
    time_remaining = sensor.time_remaining;
    server = sensor.server;

    return *this;
}

/**
 * Update the sensor
 */
void Sensor::update() {
    if (time_remaining > 0) {
        time_remaining--;
        return;
    }
    execute();
    time_remaining = duration;
}

/**
 * Display the sensor
 * @param os output stream
 */
void Sensor::display(std::ostream &os) const {
    os << id << ";" << type << ";";
}

/**
 * Display the sensor with the << operator
 * @param os output stream
 * @param obj sensor to display
 * @return the output stream
 */
std::ostream & operator<<(std::ostream &os, const Sensor &obj) {
    obj.display(os);
    return os;
}
