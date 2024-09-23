//
// Created by arnaud on 23 Sep 2024.
//

#ifndef AP4A_PROJET_SENSOR_H
#define AP4A_PROJET_SENSOR_H

#include <string>
#include "server.h"

class Sensor {
private:
    static std::string id;
    std::string defaultType;
    float data;

    Server *server;

    int duree;

public:
    Sensor();

    Sensor(const Sensor &s);

    virtual ~Sensor();

    void update();

    void execute();
};

#endif //AP4A_PROJET_SENSOR_H
