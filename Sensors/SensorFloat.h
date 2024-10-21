//
// Created by arnaud on 21/10/24.
//

#ifndef SENSORFLOAT_H
#define SENSORFLOAT_H
#include "Data.h"
#include "Sensor.h"
#include <random>


class SensorFloat: public Sensor, public Data<float>
{
private:
    float exemple_mean = 15.0;
    float exemple_std_dev = 5.0;
public:
    SensorFloat(Server *server, int duration, std::string type)
        : Sensor(server, duration, std::move(type)), Data() {}

    SensorFloat(Server *server, int duration, const std::string &type_, float exemple_mean, float exemple_std_dev)
        : Sensor(server, duration, type_), Data(),
          exemple_mean(exemple_mean),
          exemple_std_dev(exemple_std_dev) {
    }

    void execute() override;

    void display(std::ostream &os) const override;

    friend std::ostream & operator<<(std::ostream &os, const SensorFloat &obj);
};



#endif //SENSORFLOAT_H
