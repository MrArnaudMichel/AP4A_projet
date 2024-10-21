//
// Created by arnaud on 21/10/24.
//

#ifndef SENSORINTEGER_H
#define SENSORINTEGER_H
#include "Data.h"
#include "Sensor.h"


class SensorInteger: public Sensor, public Data<int>
{
public:
    SensorInteger(Server *server, int duration, std::string type)
        : Sensor(server, duration, std::move(type)), Data() {}

    void execute() override;

    void display(std::ostream &os) const override {
        Sensor::display(os);
        os << *this;
    }

    friend std::ostream & operator<<(std::ostream &os, const SensorInteger &obj) {
        return os
               << static_cast<const Data<int> &>(obj);
    }
};



#endif //SENSORINTEGER_H
