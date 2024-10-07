//
// Created by arnaud on 23 Sep 2024.
//

#ifndef AP4A_PROJET_SENSOR_H
#define AP4A_PROJET_SENSOR_H

#include <string>
#include <ostream>
#include "server.h"

#include "data.h"

using namespace std;

template <class T>class Sensor {
    string id;
    Data<T> *data;

    Server *server;

    int timeRemain;

public:
    int duree;


public:
    Sensor();
    Sensor(const Sensor &s);
    Sensor(string id, int duree, Server *server);
    virtual ~Sensor();

    virtual void update();
    virtual void execute();

    friend ostream &operator<<(ostream &os, const Sensor &sensor);

    string getId();
    float getData() const;
};

#endif //AP4A_PROJET_SENSOR_H
