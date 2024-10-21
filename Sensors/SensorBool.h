//
// Created by arnaud on 21/10/24.
//

#ifndef SENSORLIGHT_H
#define SENSORLIGHT_H
#include <ostream>
#include <utility>

#include "Data.h"
#include "Sensor.h"


class SensorBool: public Sensor, public Data<bool>
{
public:
    SensorBool(Server *server, int duration, std::string type)
        : Sensor(server, duration, std::move(type)), Data() {}

    void execute() override;

    void display(std::ostream &os) const override;

    friend std::ostream & operator<<(std::ostream &os, const SensorBool &obj);
};



#endif //SENSORLIGHT_H
