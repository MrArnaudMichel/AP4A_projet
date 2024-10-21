//
// Created by arnaud on 21/10/24.
//

#ifndef SENSORLIGHT_H
#define SENSORLIGHT_H
#include <ostream>

#include "Data.h"
#include "Sensor.h"


class SensorLight: public Sensor, public Data<bool>
{
public:
    SensorLight(Server *server, int duration)
        : Sensor(server, duration), Data() {
    }

    void execute() override;

    std::ostream & toString() const override {
        return std::cout << "SensorLight: " << static_cast<const Sensor &>(*this) << ' ' << static_cast<const Data<bool> &>(*this) << std::endl;
    }

    friend std::ostream & operator<<(std::ostream &os, const SensorLight &obj) {
        std::cout << "SensorLight: ";
        return os
               << static_cast<const Sensor &>(obj)
               << ' ' << static_cast<const Data<bool> &>(obj);
    }
};



#endif //SENSORLIGHT_H