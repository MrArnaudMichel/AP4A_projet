//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

int main() {
    Server server;
    Sensor sensor(&server, 1);
    Sensor sensor2(&server, 2);
    Sensor sensor3(&server, 3);

    Scheduler scheduler;
    scheduler.addSensor(&sensor);
    scheduler.addSensor(&sensor2);
    scheduler.addSensor(&sensor3);

    scheduler.simulation();
}
