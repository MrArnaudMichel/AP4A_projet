//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

#include "SensorLight.h"

int main() {
    Server server;
    SensorLight sensor_light(&server, 2, "light");

    Scheduler scheduler;
    scheduler.addSensor(&sensor_light);

    scheduler.simulation();
}
