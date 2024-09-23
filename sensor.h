//
// Created by arnaud on 23 Sep 2024.
//

#ifndef AP4A_PROJET_SENSOR_H
#define AP4A_PROJET_SENSOR_H

#include <string>
#include <ostream>
#include "server.h"

class Sensor {
private:
    std::string id;
    std::string defaultType;
    float data;

    Server *server;

    int duree;
    int timeRemain;

public:
    Sensor();
    Sensor(const Sensor &s);

    Sensor(const string &id, const string &defaultType, int duree, Server *server);

    virtual ~Sensor();

    void update();
    void execute();

    friend ostream &operator<<(ostream &os, const Sensor &sensor);
};

#endif //AP4A_PROJET_SENSOR_H
