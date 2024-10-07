//
// Created by arnaud on 07/10/24.
//

#ifndef SLIGHT_H
#define SLIGHT_H

#include "sensor.h"

class Slight : public Sensor {

public:
    Slight();
    ~Slight();
    float read();
private:

};



#endif //SLIGHT_H
