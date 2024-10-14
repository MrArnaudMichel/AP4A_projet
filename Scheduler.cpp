//
// Created by arnaud on 14/10/24.
//

#include "Scheduler.h"

#include <unistd.h>

bool Scheduler::running = true;

Scheduler::Scheduler(const Scheduler &scheduler) {
    for (auto &sensor : scheduler.sensors) {
        sensors.push_back(new Sensor(*sensor));
    }
}

Scheduler::~Scheduler() {
    for (auto &sensor : sensors) {
        delete sensor;
    }
}

Scheduler & Scheduler::operator=(const Scheduler &scheduler) {
    if (this == &scheduler) {
        return *this;
    }
    for (auto &sensor : sensors) {
        delete sensor;
    }
    sensors.clear();
    for (auto &sensor : scheduler.sensors) {
        sensors.push_back(new Sensor(*sensor));
    }
    return *this;
}

void Scheduler::addSensor(Sensor *sensor) {
    sensors.push_back(sensor);
}

void signalHandler(const int signum) {
    std::cout << "\n Interrupt signal (" << signum << ") received.\n";
    Scheduler::running = false;
    exit(signum);
}

void Scheduler::simulation() {
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    while (running) {
        sleep(1);
        for (auto &sensor : sensors) {
            sensor->update();
        }
    }
}
