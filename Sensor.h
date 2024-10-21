//
// Created by arnaud on 14/10/24.
//

#ifndef SENSOR_H
#define SENSOR_H

#include <ostream>
#include <iostream>
#include <utility>

#include "Server.h"
class Server;
class Sensor {
private:
    static int CONST_ID;
    int id;

    int duration;
    int timeRemaining;

protected:
    Server *server;
    std::string type;
public:
    Sensor() : id(CONST_ID++), server(nullptr), duration(0), timeRemaining(0) {}
    Sensor(const Sensor &sensor) : id(CONST_ID++), server(sensor.server), duration(sensor.duration), timeRemaining(sensor.timeRemaining) {}

    virtual ~Sensor() = default;
    Sensor &operator=(const Sensor &sensor);

    Sensor(Server *server, const int duration, std::string type_) : id(CONST_ID++), duration(duration), timeRemaining(duration), server(server), type(std::move(type_)) {}
    void update();
    virtual void execute() = 0;

    virtual void affiche() const = 0;

    friend std::ostream & operator<<(std::ostream &os, const Sensor &obj) {
        return os << obj.id << ";"  << obj.type << ";";
    }
};



#endif //SENSOR_H
