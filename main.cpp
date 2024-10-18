//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

int main() {
    Server server;
    Sensor sensor(&server, "float", 1);
    Sensor sensor2(&server, "int", 2);
    Sensor sensor3(&server, "int", 3);

    Scheduler scheduler;
    scheduler.addSensor(&sensor);
    scheduler.addSensor(&sensor2);
    scheduler.addSensor(&sensor3);

    scheduler.simulation();
}
