//
// Created by arnaud on 23 Sep 2024.
//

#include <csignal>
#include "scheduler.h"

Scheduler::Scheduler() {}

Scheduler::~Scheduler() {

}

[[noreturn]] void Scheduler::simulation() {
    while (true) {
        // TODO: Activer les capteur à chaque seconde
        sleep(1);
        std::cout << "Test" << std::endl;

        for (auto *s: sensors) {
            s->update();
        }
    }
}

void Scheduler::addSensor(Sensor *s) {
    this->sensors.push_back(s);
}
