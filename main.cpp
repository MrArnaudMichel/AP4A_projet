//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

int main() {
    Server server;
    Sensor sensor(&server, 2);

    Scheduler scheduler;
    scheduler.addSensor(&sensor);

    scheduler.simulation();
}
