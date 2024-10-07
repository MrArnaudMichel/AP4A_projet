//
// Created by arnaud on 07/10/24.
//

#ifndef SLIGHT_H
#define SLIGHT_H

#include "Sensor.h"
class Slight : public Sensor<bool> {
public:
    ~Slight() override;
    void update() override;
    void execute() override;
};


#endif //SLIGHT_H
