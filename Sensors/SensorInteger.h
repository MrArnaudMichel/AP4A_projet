//
// Created by arnaud on 21/10/24.
//

#ifndef SENSORINTEGER_H
#define SENSORINTEGER_H
#include "Data.h"
#include "Sensor.h"
#include <random>


class SensorInteger: public Sensor, public Data<int>
{
public:
    SensorInteger(Server *server, int duration, std::string type)
        : Sensor(server, duration, std::move(type)), Data() {}

    void execute() override;
    void display(std::ostream &os) const override;

    // Operator overloading
    friend std::ostream & operator<<(std::ostream &os, const SensorInteger &obj);
};



#endif //SENSORINTEGER_H
