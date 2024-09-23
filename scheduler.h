//
// Created by arnaud on 23 Sep 2024.
//

#ifndef AP4A_PROJET_SCHEDULER_H
#define AP4A_PROJET_SCHEDULER_H

#include <vector>
#include <sensor.h>

class Scheduler {
private:
    std::vector<Sensor *> sensors;
public:
    Scheduler();

    virtual ~Scheduler();

    [[noreturn]] void simulation();

    void addSensor(Sensor *s);
};

#endif //AP4A_PROJET_SCHEDULER_H
