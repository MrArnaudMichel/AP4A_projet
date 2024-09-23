//
// Created by arnaud on 23 Sep 2024.
//

#include "sensor.h"

Sensor::Sensor() {
    id = "0";
    data = 0;
    defaultType = "float";
    server = nullptr;
    duree = 2;

}

Sensor::Sensor(const Sensor &s) {
}

Sensor::~Sensor() {
    delete this->server;
}

void Sensor::update() {
    // simuler une mesure toute les x secondes
    if (duree == 0) {
        execute();
        duree = 2;
    } else {
        duree--;
    }
}

void Sensor::execute() {

}