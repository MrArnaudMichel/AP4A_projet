//
// Created by arnaud on 14/10/24.
//

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Sensors/Sensor.h"
#include <csignal>


class Scheduler {
private:
    std::vector<Sensor *> sensors;
public:
    static bool running;

    //////////////////////////////
    /// Coplien architecture /////
    //////////////////////////////
    Scheduler() = default;
    Scheduler(const Scheduler &scheduler);
    virtual ~Scheduler();
    Scheduler &operator=(const Scheduler &scheduler);

    void addSensor(Sensor *sensor);

    void simulation();
};



#endif //SCHEDULER_H
