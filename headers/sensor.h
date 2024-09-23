//
// Created by arnaud on 23 Sep 2024.
//

#ifndef AP4A_PROJET_SENSOR_H
#define AP4A_PROJET_SENSOR_H

#include <string>

class Sensor{
private:
    static std::string id;

public:
    Sensor();
    Sensor(const Sensor& s);

    virtual ~Sensor();


};

#endif //AP4A_PROJET_SENSOR_H
