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
    float example_mean = 15.0;
    float example_std_dev = 5.0;
public:
    // Constructors
    SensorFloat(Server *server, int duration, std::string type, std::string unit)
        : Sensor(server, duration, std::move(type), std::move(unit)), Data() {}
    SensorFloat(Server *server, int duration, const std::string &type_, std::string unit, float example_mean, float example_std_dev)
        : Sensor(server, duration, type_, std::move(unit)), Data(),
          example_mean(example_mean),
          example_std_dev(example_std_dev) {
    }

    void execute() override;
    void display(std::ostream &os) const override;

    // Operator overloading
    friend std::ostream & operator<<(std::ostream &os, const SensorFloat &obj);
};



#endif //SENSORFLOAT_H
