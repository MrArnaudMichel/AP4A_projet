//
// Created by arnaud on 14/10/24.
//

#ifndef SENSOR_H
#define SENSOR_H

#include "Server.h"

class Sensor {
private:
    static int id;
    Server *server;

    int duration;
    int timeRemaining;
public:
    Sensor();
    Sensor(const Sensor &sensor);
    virtual ~Sensor() = default;
    Sensor &operator=(const Sensor &sensor);

};



#endif //SENSOR_H
