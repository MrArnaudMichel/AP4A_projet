//
// Created by arnaud on 21/10/24.
//

#ifndef SENSORFLOAT_H
#define SENSORFLOAT_H
#include "Data.h"
#include "Sensor.h"


class SensorFloat: public Sensor, public Data<float>
{
public:
    SensorFloat(Server *server, int duration, std::string type)
        : Sensor(server, duration, std::move(type)), Data() {}

    void execute() override;

    void display(std::ostream &os) const override {
        Sensor::display(os);
        os << *this;
    }

    friend std::ostream & operator<<(std::ostream &os, const SensorFloat &obj) {
        return os
               << static_cast<const Data<float> &>(obj);
    }
};



#endif //SENSORFLOAT_H
