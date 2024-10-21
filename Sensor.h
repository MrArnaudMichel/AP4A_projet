//
// Created by arnaud on 14/10/24.
//

#ifndef SENSOR_H
#define SENSOR_H

#include <ostream>
#include <utility>

#include "Server.h"
class Server;
class Sensor final {
private:
    static int CONST_ID;


    int id;
    Server *server;
    std::string valueType;

    int duration;
    int timeRemaining;
public:
    Sensor() : id(CONST_ID++), server(nullptr), duration(0), timeRemaining(0) {}
    Sensor(const Sensor &sensor) : id(CONST_ID++), server(sensor.server), duration(sensor.duration), timeRemaining(sensor.timeRemaining) {}
    ~Sensor() = default;
    Sensor &operator=(const Sensor &sensor);

    Sensor(Server *server, int duration) : id(CONST_ID++), server(server), duration(duration), timeRemaining(duration) {}
    void update();
    virtual void execute();

    friend std::ostream & operator<<(std::ostream &os, const Sensor &obj) {
        return os << obj.id << ";";
    }
};



#endif //SENSOR_H
