//
// Created by arnaud on 14/10/24.
//

#include "Scheduler.h"
#include <unistd.h>

// Static variable initialization
bool Scheduler::running = true;

/**
 * Copy constructor for Scheduler
 * The sensors are copied, but they are not deep copied because sensor is an abstract class
 * @param scheduler scheduler to copy
 */
Scheduler::Scheduler(const Scheduler &scheduler) {
    for (auto &sensor : scheduler.sensors) {
        sensors.push_back(sensor);
    }
}

/**
 * Destructor for Scheduler
 * Delete all sensors (if there is a copy of this scheduler, the sensors will also be deleted)
 */
Scheduler::~Scheduler() {

}

/**
 * Copy operator for Scheduler
 * The sensors are copied, but they are not deep copied because sensor is an abstract class
 * @param scheduler scheduler to copy
 * @return the copied scheduler
 */
Scheduler & Scheduler::operator=(const Scheduler &scheduler) {
    if (this == &scheduler) {
        return *this;
    }
    for (auto &sensor : sensors) {
        delete sensor;
    }
    sensors.clear();
    for (auto &sensor : scheduler.sensors) {
        sensors.push_back(sensor);
    }
    return *this;
}

/**
 * Add a sensor to the scheduler
 * @param sensor sensor to add
 */
void Scheduler::addSensor(Sensor *sensor) {
    sensors.push_back(sensor);
}

/**
 * Add a server to the scheduler
 * @param server server to add
 */
void Scheduler::addServer(Server *server) {
    servers.push_back(server);
}

/**
 * Signal handler for Ctrl+C and kill
 * Stop the scheduler
 * @param signum signal number
 */
void signalHandler(const int signum) {
    std::cout << BOLDBLUE << "\nInterrupt signal (" << signum << ") received.\n" << RESET;
    Scheduler::running = false;
}

/**
 * Simulation of the scheduler
 * Update all sensors every second
 */
void Scheduler::simulation() {
    signal(SIGINT, signalHandler); // Ctrl+C
    signal(SIGTERM, signalHandler); // kill
    while (running) {
        sleep(1);
        for (auto &sensor : sensors) {
            sensor->update();
        }
        for (auto &server : servers) {
            server->update();
        }
    }
    std::cout << BOLDRED << "Scheduler stopped" << RESET << std::endl;
}