//
// Created by arnaud on 14/10/24.
//

#ifndef SENSOR_H
#define SENSOR_H

#include <ostream>

#include "Server.h"
class Server;
class Sensor {
private:
    static int CONST_ID;
    int id;
    Server *server;

    float value;

    int duration;
    int timeRemaining;
public:
    Sensor() : id(CONST_ID++), server(nullptr), value(0), duration(0), timeRemaining(0) {}
    Sensor(const Sensor &sensor) : id(CONST_ID++), server(sensor.server), value(0), duration(sensor.duration), timeRemaining(sensor.timeRemaining) {}    virtual ~Sensor() = default;
    Sensor &operator=(const Sensor &sensor);

    Sensor(Server *server, int duration) : id(CONST_ID++), server(server), value(0), duration(duration), timeRemaining(duration) {}
    void update();
    void execute();

protected:
    float getValue() const {
        return value;
    }

    void setValue(float value) {
        this->value = value;
    }

public:
    friend std::ostream & operator<<(std::ostream &os, const Sensor &obj) {
        return os << obj.id << ";" << obj.value;
    }
};



#endif //SENSOR_H
