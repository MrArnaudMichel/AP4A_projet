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
    int time_remaining;

protected:
    Server *server;
    std::string type;
public:
    //////////////////////////////
    /// Coplien architecture /////
    //////////////////////////////
    Sensor() : id(CONST_ID++), server(nullptr), duration(0), time_remaining(0) {}
    Sensor(const Sensor &sensor) : id(CONST_ID++), server(sensor.server), duration(sensor.duration), time_remaining(sensor.time_remaining) {}
    virtual ~Sensor() = default;
    Sensor &operator=(const Sensor &sensor);

    Sensor(Server *server, const int duration, std::string type_) : id(CONST_ID++), duration(duration), time_remaining(duration), server(server), type(std::move(type_)) {}

    void update();
    virtual void execute() = 0;
    virtual void display(std::ostream& os) const;

    // Operator overloading
    friend std::ostream & operator<<(std::ostream &os, const Sensor &obj);
};



#endif //SENSOR_H
